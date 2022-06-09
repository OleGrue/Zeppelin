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

#include "loopthread.h"

//constructor
LoopThread::LoopThread(QObject* parent)
{
    //initialize variables
    int amountPorts = 0;
    m_counter = 0;
    m_active = false;

    //get user input on which ports are used
    m_rcmodel.setInitialData(m_dataSet);

    //loop through all outputs
    for(int i = 0; i < Constants::OUTPUTS; i++)
    {
        //output has a motor or servo attached
        if(m_dataSet.getPortType(i) == 'm' || m_dataSet.getPortType(i) == 's')
        {
            //count the ports that are used
            amountPorts++;
        }
    }    

    //initialize loop
    m_active = true;

    m_xBee = new Sender();

    m_thread = new QThread();
    m_thread->start();
    m_xBee->moveToThread(m_thread);

    connect(this, SIGNAL(addData(char)),
            m_xBee, SLOT(addData(char)), Qt::BlockingQueuedConnection);

    connect(this, SIGNAL(addData(std::vector<char>, int)),
            m_xBee, SLOT(addData(std::vector<char>, int)), Qt::BlockingQueuedConnection);

    connect(this, SIGNAL(sendUpdate(OutputDataSet*)),
            m_xBee, SLOT(sendUpdate(OutputDataSet*)), Qt::BlockingQueuedConnection);

    connect(this, SIGNAL(sendData()),
            m_xBee, SLOT(sendData()));

    connect(parent, SIGNAL(connectSender()),
            m_xBee, SLOT(connectSender()));

    connect(parent, SIGNAL(disconnectSender()),
            m_xBee, SLOT(disconnectSender()));

    connect(m_xBee, SIGNAL(disconnected(QString)),
            parent, SLOT(disconnected(QString)));


    //connection for function setVoltage
    QObject::connect(m_xBee, SIGNAL(setVoltage(int)),
                     parent, SLOT(setVoltage(int)));

    QObject::connect(m_xBee, SIGNAL(sendTextOut(QString str)), parent, SLOT(sendTextOut(QString str)));

    //save the used ports as static variable
    Constants::s_outputsUsed = amountPorts;
}

LoopThread::~LoopThread()
{
    m_thread->quit();
    m_thread->wait();
}

void LoopThread::run()
{
    int arrayIndex = 0;

    //inifinite loop while programm active
    while(m_active)
    {
        //increase counter
        m_counter++;

        //refreshes VGP Data (schreiben vom haupthread)
        emit askForVGPData();

        //get current type of control
        if(m_virtualGP.getUseGP())
        {
            m_xBoxC.updateData();

            //if it's the gamepad use that one
            m_rcmodel.calculateOutput(m_xBoxC.getDataSet(), m_dataSet);
        }
        else
        {
            //otherwise use the virtual one
            m_rcmodel.calculateOutput(m_virtualGP.getDataSet(), m_dataSet);
        }

        //see whether we are currently sending data
        if(m_xBee->isActive())
        {
            //triggered every second
            if(m_counter % 10 == 0)
            {
                //send request for voltage update
                emit addData(CMD_ADC_VOLT);
            }

            //if so send a new update
            emit sendUpdate(&m_dataSet);

        #ifdef DEBUG_SEND
            //get data stream as text output
            emit sendTextOut(m_xBee->sendData());
        #else
            //send data to airship
            emit sendData();
        #endif

            //and set status to sending
            emit setStatus("Sending", "#088A29");

            //write status update
            emit sendTextOut("Sending");        
        }
        //if there wasn't currently an emergency shutdown
        else
        {
            //set status to running
            emit setStatus("Running", "#088A29");
        }

        //reset array index for statusbars
        arrayIndex = 0;

        //iterate through every output
        for(int i = 0; i < Constants::OUTPUTS; i++)
        {
            //see whether current port is relevant
            if(m_dataSet.getPortType(i) == 'm' || m_dataSet.getPortType(i) == 's')
            {
                //update progressbar
                emit setPBValue(arrayIndex++, m_dataSet.getOutputData(i));
            }
        }

        //refresh gui
        emit refreshSurface();

        //update table
        emit setGPTable(m_xBoxC.getDataSet());

        //time to sleep in msec
        msleep(100);
    }
}

//stop the infinite loop
void LoopThread::stopThread()
{
    //set infinite loop inactive
    m_active = false;
}

//return the surface input
SurfaceInput* LoopThread::getSurfaceInput()
{
    return &m_virtualGP;
}

//return data set containing the ports and their types
OutputDataSet LoopThread::getPorts()
{
    return m_dataSet;
}
