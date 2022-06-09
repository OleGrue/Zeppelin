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

#ifndef LOOPTHREAD_H
#define LOOPTHREAD_H

#include <QThread>
#include <QSerialPort>
#include "gamepad.h"
#include "surfaceinput.h"
#include "rc_model.h"
#include "sender.h"
#include "outputdataset.h"

class LoopThread : public QThread
{
    //initialize as qobject
    Q_OBJECT

public:
    //constructor
    explicit LoopThread(QObject *parent);

    ~LoopThread();

    //stop execution of thread
    void stopThread(void);

    //get surface input
    SurfaceInput* getSurfaceInput(void);

    //get output data
    OutputDataSet getPorts(void);

    void connectSender(void);
    void disconnectSender(void);

private:
    //membervariables
    int m_counter;
    bool m_active;
    Sender* m_xBee;
    QThread* m_thread;
    Gamepad m_xBoxC;
    SurfaceInput m_virtualGP;
    RCModel m_rcmodel;
    OutputDataSet m_dataSet;

protected:
    //function to run for this thread
    void run(void);

signals:
    //signals connected to mainwindow (see description there)
    void askForVGPData(void);
    void refreshSurface(void);
    void setVoltage(int voltage);
    void setPBValue(int progBar, int value);
    void setGPTable(InputDataSet DataSet);
    void sendTextOut(QString str);
    void setStatus(QString message, QString colour);

    void addData(char);
    void addData(std::vector<char>, int);
    void sendUpdate(OutputDataSet*);
    void sendData(void);
};

#endif // LOOPTHREAD_H

