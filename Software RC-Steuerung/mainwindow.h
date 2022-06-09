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
 *
 * All pictures are released under the same license as this software, unless stated otherwise.
 * For more information about the pictures see below:
 *
 * "360 controller" by Alphathon - Own work.
 * Licensed under Creative Commons Attribution-Share Alike 3.0 via Wikimedia Commons -
 * http://commons.wikimedia.org/wiki/File:360_controller.svg#mediaviewer/File:360_controller.svg
 * - revised by Julian Engelskirchen
 *
 * brushless-motor.png and servo.png
 * created by Volker Rudat
 *
 * emergency-button.png
 * created by Julian Engelskirchen
 ************************************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThreadPool>
#include <stdlib.h>
#include "surfaceinput.h"
#include "inputdataset.h"
#include "loopthread.h"
#include "statusbar.h"
#include "constants.h"
#include "virtualgamepad.h"

Q_DECLARE_METATYPE(InputDataSet)

namespace Ui
{
    class MainWindow;
}

//needed to solve dependencies
class StatusBar;
class LoopThread;

class MainWindow : public QMainWindow
{
    //initialize as QObject
    Q_OBJECT

public:
    //constructor
    explicit MainWindow(QWidget *parent = 0);

    //destructor
    ~MainWindow();

    //kill thread
    void killLoop(void);

private:
    //member variables
    Ui::MainWindow* m_ui;
    VirtualGamePad* m_pad;
    SurfaceInput* m_SI;
    LoopThread* m_loop;
    QString m_sendstr[Constants::SOLN];
    std::vector<StatusBar*> m_statusBarList;
    QString m_status;

    //initializer functions
    void initList(void);
    void initStatusBars(void);
    void initTable(void);
    void initThread(void);

    //convert boolean to string
    QString stringTextBGPT(bool b);

    //convert inputs of directional pad to string
    QString stringTextDPGPT(bool d, bool u, bool r, bool l);

signals:
    void connectSender(void);
    void disconnectSender(void);


public slots:
    //slots connecting to thread
    void refreshSurface();

    //set data for virtual gamepad
    void setVGPData();

    //set value of progressbar
    void setPBValue(int progBar, int value);

    //send status text to gui
    void sendTextOut(QString str);

    //set values of gamepad table
    void setValuesGPTable(InputDataSet DataSet);

    //set coloured status message
    void setStatus(QString message, QString colour);

    //set voltage of battery
    void setVoltage(int voltage);

    void disconnected(QString reason);

private slots:
    //slots connecting to gui
    void on_pushButton_reset_clicked(void);
    void on_button_run_clicked(void);
    void on_button_emergency_clicked(void);
    void on_tabWidget_currentChanged(int index);
};

#endif // MAINWINDOW_H
