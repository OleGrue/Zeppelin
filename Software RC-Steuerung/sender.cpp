/************************************************************************************************
 * Copyright (C) 2014
 *
 * Authors:
 * Till Staude
 * Julian Engelskirchen
 *
 * The "RC-Steuerung"-programm is free software: you can redistribute it
 * and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, either version 3 of the License,
 * or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 ************************************************************************************************/

#include "Sender.h"

//constructor
Sender::Sender() : m_closing(false)
{
    m_port = new QSerialPort(this);
    m_port->setBaudRate(BAUDRATE);
    m_port->setDataBits(DATABITS);
    m_port->setParity(PARITY);
    m_port->setStopBits(STOPBITS);
    m_port->setFlowControl(FLOW);

    connect(m_port, SIGNAL(readyRead()), SLOT(handleReceived()));

    connect(m_port, SIGNAL(error(QSerialPort::SerialPortError)),
            SLOT(handleError(QSerialPort::SerialPortError)));
}

//destructor
Sender::~Sender()
{
    delete m_port;
}

void Sender::handleError(QSerialPort::SerialPortError err)
{
    if(err == QSerialPort::WriteError || err == QSerialPort::ResourceError)
    {
        m_port->close();
        emit disconnected("Sender unplugged.");
    }
}

//creates an update stream
void Sender::sendUpdate(OutputDataSet* newData)
{
    //iterate through all outputs
    for(int i = 0; i < Constants::OUTPUTS; i++)
    {
        //check whether new data is available
        if(m_data.getOutputData(i) != newData->getOutputData(i))
        {
            //check whether the new data equals zero
            if(newData->getOutputData(i) == 0)
            {
                //append the correct motor off command
                m_stream.push_back(CMD_OUT_OFF + i);
            } else
            {
                //append the correct motor command
                m_stream.push_back(CMD_OUT + i);

                //append the new value of the motor
                m_stream.push_back((unsigned char)(newData->getOutputData(i) / 8) + 125);
            }
        }
    }

    //Send GPIOs
    //check whether new data is available
    if(m_data.getGPIOData() != newData->getGPIOData()){
        m_stream.push_back(CMD_GPIO_OUT);
        //Append data
        m_stream.push_back(newData->getGPIOData() | 0x80);
    }

    //Send GPIO Enable
    //check whether new data is available
    //if((m_data.getGPIODir() != newData->getGPIODir()) && (newData->getGPIODir() != 0)){
    if((m_data.getGPIODir() != newData->getGPIODir())){
        m_stream.push_back(CMD_GPIO_DIR);
        //Append data
        m_stream.push_back(newData->getGPIODir() | 0x80);
    }

    //check whether there had been new data
    if(m_stream.empty())
    {
        //if not add awake command
        m_stream.push_back(CMD_AWAKE);
    }

    //copy new data
    m_data.copy(*newData);
}

//maually add data to output stream
void Sender::addData(std::vector<char> newData, int size)
{
    //iterate through size of new data
    for(int i = 0; i < size; i++)
    {
        //append new data to stream
        m_stream.push_back(newData[i]);
    }
}

//manually add a single character to the stream
void Sender::addData(char newData)
{
    m_stream.push_back(newData);
}

//send data
QString Sender::sendData()
{
    //initialize variables
    QByteArray streamSend = QByteArray();
    QString out;
    int streamSize = 0;

    //iterate through all list entries (except last)
    for(std::vector<char>::const_iterator it = m_stream.cbegin(); it != m_stream.cend(); it++)
    {
        //not more than maximum commands per stream
        if(streamSize >= (MAX_COMMANDS - 1))
        {
            break;
        }
        //add character to stream
        streamSend.append(*it);

        //write send char as hexadecimal to gui
        out.append(QString::number(*it, 16) + ",");
    }

    //delete stream
    m_stream.clear();

    //add end cmd to output
    out.append(QString::number(CMD_END, 16));

    //and to stream
    streamSend.append(CMD_END);

    //send stream away
    m_port->write(streamSend);

    //return output string
    return out;
}

//get a stream of received dats
void Sender::handleReceived(void)
{   
    //initialize variables
    QByteArray stream;
    int voltage;

    //get answers
    stream = m_port->readAll();

    //iterate through all the answers
    for(int i = 0; i < stream.size(); i++)
    {
        //look what the answers was
        switch(stream[i])
        {
            //answer was a voltage read
            case CMD_ADC_VOLT:
                //check whether there are 2 bytes left
                if(i < stream.size() - 2)
                {
                    //rebuild voltage from 2 bytes
                    voltage = (stream[++i] << 8);

                    //and send it to gui
                    emit setVoltage(voltage + (unsigned char)stream[++i]);
                }
                break;
        case CMD_ADC_RAW:{

            //rebuild voltage from 2 bytes
            uint16_t temp;
            temp = (stream[++i] << 8);
            temp |= (stream[++i]);
            std::cout << "Received raw voltage value: "
                      << std::hex
                      << temp
                      << std::dec
                      << std::endl;

        }break;
        case CMD_VERSION:{
            uint16_t version;
            version = (stream[++i] << 8);
            version |= (stream[++i]);

            std::cout << "Detected FW Version: "
                      << std::hex
                      << version
                      << std::dec
                      << std::endl;
        }break;
         case CMD_GPIO_IN:
        {
            std::cout << "GPIO Input handling not implemented"
                      << std::endl;
        }break;

            //answer unknown
            default:
                //make a status report
                std::cout << "Error, unknown cmd received.: "
                          << std::hex
                          << (int)stream[i]
                          << std::dec
                          << std::endl;
        }
    }
}

//try to connect a sender to the pc
void Sender::connectSender()
{

    emit sendTextOut("Sender TEST");

    //check whether a sender is already connected
    if(m_port->isOpen())
    {
        return;
    }

    for(auto& availablePort : QSerialPortInfo::availablePorts())
    {
        /* code to find correct com device
        qDebug() << availablePort.description() << ", ";
        qDebug() << availablePort.manufacturer() << ", ";
        qDebug() << availablePort.portName() << ", ";
        qDebug() << availablePort.productIdentifier() << ", ";
        qDebug() << availablePort.vendorIdentifier();*/

        if(availablePort.manufacturer() == Constants::NAME
           && availablePort.vendorIdentifier() == Constants::VENDOR_ID)
        {
            m_port->setPort(availablePort);
            if(!m_port->open(QIODevice::ReadWrite))
            {
                emit disconnected("Could not connect to Device.");
                return;
            }
            return;
        }
    }

    emit disconnected("No sender connected.");
    //print an error message and quit
    return;
}

//disconnect from a sender
void Sender::disconnectSender()
{
    //check whether connected at all
    if(m_port->isOpen())
    {
        m_closing = true;

        //shut everything off
        addData(CMD_EMERGENCY);

        //send data away
        sendData();

        //and close port
        m_port->flush();
        m_port->close();
        m_closing = false;
    }
}

//get connection state
bool Sender::isActive()
{
    return m_port->isOpen() & !m_closing;
}
