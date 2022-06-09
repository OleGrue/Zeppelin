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

#ifndef SENDER_H
#define SENDER_H

#include "outputdataset.h"
#include "rs232.h"
#include "constants.h"
#include <vector>
#include <QObject>
#include <QTimer>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

/*maximum commands in buffer*/
#define MAX_COMMANDS 100

/*end of command stream*/
#define CMD_END 0x7D

/*emergency*/
#define CMD_EMERGENCY 0x01

/*set value of outputs*/
#define CMD_OUT 0x10
#define CMD_OUT1 0x10
#define CMD_OUT2 0x11
#define CMD_OUT3 0x12
#define CMD_OUT4 0x13
#define CMD_OUT5 0x14
#define CMD_OUT6 0x15
#define CMD_OUT7 0x16
#define CMD_OUT8 0x17

/*set output to midvalue*/
#define CMD_OUT_OFF 0x20
#define CMD_OUT1_OFF 0x20
#define CMD_OUT2_OFF 0x21
#define CMD_OUT3_OFF 0x22
#define CMD_OUT4_OFF 0x23
#define CMD_OUT5_MID 0x24
#define CMD_OUT6_MID 0x25
#define CMD_OUT7_MID 0x26
#define CMD_OUT8_MID 0x27

/*set multiple outputs to midvalue*/
#define CMD_OUT1TO4_MID 0x30
#define CMD_OUT5TO8_MID 0x31

/*get read of battery voltage*/
#define CMD_ADC_RAW     0x40
#define CMD_ADC_VOLT	0x41

/*Version Information*/
#define CMD_VERSION		0x49

/*control GPIO Port*/
#define CMD_GPIO_OUT	0x50
#define CMD_GPIO_IN		0x51
#define CMD_GPIO_DIR	0x52

/*command for sending awake signal*/
#define CMD_AWAKE 0x00

class Sender : public QObject
{
    Q_OBJECT

public:
    //constructor
    explicit Sender();

    //destructor
    ~Sender();   

protected:
    void run(void);

signals:
    void setVoltage(int voltage);
    void sendTextOut(QString str);
    void disconnected(QString reason);

public slots:
    //construct update for sending to airship
    void sendUpdate(OutputDataSet* newData);

    //add data for sending to airship
    void addData(std::vector<char> newData, int size);
    void addData(char newData);

    //receive data
    void handleReceived(void);

    //get whether updates are send to airship
    bool isActive(void);

    //send data to airship
    QString sendData(void);

    void connectSender(void);
    void disconnectSender(void);

    void handleError(QSerialPort::SerialPortError err);

private:
    //membervariables
    QSerialPort* m_port;
    QTimer* m_timer;
    int m_streamSize;
    bool m_closing;
    OutputDataSet m_data;
    std::vector<char> m_stream;

    static const int TIMEOUT_MILLI = 10;
    static const QSerialPort::BaudRate BAUDRATE = QSerialPort::Baud9600;
    static const QSerialPort::DataBits DATABITS = QSerialPort::Data8;
    static const QSerialPort::Parity PARITY = QSerialPort::NoParity;
    static const QSerialPort::StopBits STOPBITS = QSerialPort::OneStop;
    static const QSerialPort::FlowControl FLOW = QSerialPort::NoFlowControl;
};

#endif // SENDER_H
