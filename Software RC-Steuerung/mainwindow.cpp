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

#include "mainwindow.h"
#include "ui_mainwindow.h"

//initialize static here because of missing .cpp file for Constants
int Constants::s_outputsUsed = 0;

const QString Constants::NAME = "FTDI";

//constructor for the mainwindow
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_loop(nullptr)
{
    //initialize the graphical user interface(GUI)
    m_ui->setupUi(this);

    m_ui->imageLabel_controller->setPixmap(QPixmap(":/images/german/XBox-360-Controller-medium.png"));

    m_pad = (VirtualGamePad*)m_ui->virtualGamePad;

    //initialize loopthread
    m_loop = new LoopThread(this);            

    //get surfaceinput
    m_SI = m_loop->getSurfaceInput();

    //initialize all the other awesome stuff
    initStatusBars();
    initTable();
    initThread();

    //make an initial update off the virtual game pad
    m_pad->updateVGPValues();

    //set status to crashed so if it will not be overwritten by the loop thread this will appear
    setStatus("Crashed", "#FFBF00");
}

//destructor for the main window
MainWindow::~MainWindow()
{
    //iterate through every item in the table
    for(int i = 0; i < 12; i++)
    {
        //and destroy it
        delete(m_ui->table_gamePad->item(i, 0));
    }

    //iterate through every statusbar created
    for(int i = 0; i < Constants::s_outputsUsed; i++)
    {
        //and destroy it
        delete m_statusBarList[i];
    }

    //destroy window
    delete m_ui;

    emit disconnectSender();

    //safely shut down the loop thread
    killLoop();

    //and then destroy it
    delete m_loop;
}

//initialize table containing the current states of the gamepad
void MainWindow::initTable()
{
    //iterate through all 12 gamepad parts
    for(int i = 0; i < 12; i++)
    {
        //create new item in table
        QTableWidgetItem *item = new QTableWidgetItem();
        m_ui->table_gamePad->setItem(i, 0, item);

        //make item neither selectable nor editable
        item->setFlags(item->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsSelectable);
    }
}

//initialize the statusbars
void MainWindow::initStatusBars()
{
    //create vector containing every statusbar object
    m_statusBarList = *(new std::vector<StatusBar*>());

    //iterate through all possible outputs
    for(int i = 0; i < Constants::OUTPUTS; i++)
    {
        //check whether or not the current port has a motor or servo attached
        if(m_loop->getPorts().getPortType(i) == 'm' || m_loop->getPorts().getPortType(i) == 's')
        {
            //create new statusbar for port
            m_statusBarList.push_back(new StatusBar(m_ui->widget_statusBar->layout(),
                                                    m_loop->getPorts().getPortType(i),
                                                    "Port " + QString::number(i),
                                                    m_ui->widget_statusBar));
        }
    }
}

//initialize the connections to the loopthread
void MainWindow::initThread() {
    qRegisterMetaType<InputDataSet>();

    //connection for function askForVGPData
    QObject::connect(m_loop,
                     SIGNAL(askForVGPData()),
                     this,
                     SLOT(setVGPData()),
                     Qt::QueuedConnection);

    //connection for function setPBValue
    QObject::connect(m_loop,
                     SIGNAL(setPBValue(int, int)),
                     this,
                     SLOT(setPBValue(int, int)),
                     Qt::QueuedConnection);

    //connection for function refreshSurface
    QObject::connect(m_loop,
                     SIGNAL(refreshSurface()),
                     this,
                     SLOT(refreshSurface()),
                     Qt::QueuedConnection);

    //connection for function setGPTable
    QObject::connect(m_loop,
                     SIGNAL(setGPTable(InputDataSet)),
                     this,
                     SLOT(setValuesGPTable(InputDataSet)),
                     Qt::QueuedConnection);

    //connection for function sendTextOut
    QObject::connect(m_loop,
                     SIGNAL(sendTextOut(QString)),
                     this,
                     SLOT(sendTextOut(QString)),
                     Qt::QueuedConnection);

    //connection for function setStatus
    QObject::connect(m_loop,
                     SIGNAL(setStatus(QString, QString)),
                     this,
                     SLOT(setStatus(QString, QString)),
                     Qt::QueuedConnection);

    //start execution of thread
    m_loop->start();
    //m_loop->moveSender(m_loop);
}

void MainWindow::refreshSurface()
{
    m_pad->updateVGPValues();
}

//shut down the loopthread
void MainWindow::killLoop()
{
    //stop the execution of the thread
    m_loop->stopThread();

    //give it a second to shut down
    if(!m_loop->wait(1000))
    {
        //if it hasn't shut down yet do it the hard way
        m_loop->terminate();
        m_loop->wait();
    }
}

//converts the digitalgamepad inputs into a string
QString MainWindow::stringTextDPGPT(bool d, bool u, bool r, bool l)
{
    //top right selected
    if(u && r)
    {
        return "top right";
    }

    //top left selected
    if(u && l)
    {
        return "top left";
    }

    //bottom right selected
    if(d && r)
    {
        return "bottom right";
    }

    //bottom left selected
    if(d && l)
    {
        return "bottom left";
    }

    //top selected
    if(u)
    {
        return "top";
    }

    //bottom selected
    if(d)
    {
        return "bottom";
    }

    //right selected
    if(r)
    {
        return "right";
    }

    //left selected
    if(l)
    {
        return "left";
    }

    //nothing of the previous selected
    return "none";
}

//converts gamepad button states into strings
QString MainWindow::stringTextBGPT(bool b)
{
    //button pressed
    if(b)
    {
        return "true";
    }

    //button released
    return "false";
}

//set the value of a progressbar from the statusbar
void MainWindow::setPBValue(int progBar, int value)
{
    m_statusBarList[progBar]->setProgressbar(value);
}

//set the progressbar indicating the voltage of the accu
void MainWindow::setVoltage(int value)
{

    //check whether voltage is above max
    if(value > Constants::VOLT_MAX)
    {
        //print out error
        sendTextOut("Voltage too high!");

        //set text of progressBar
        m_ui->progressBar_accu->setFormat("HIGH");

        //set value to max
        m_ui->progressBar_accu->setValue(100);

    //check whether voltage is below low
    }
    else if(value < Constants::VOLT_MIN)
    {
        //print out error
        sendTextOut("Voltage too low!");

        //set text of progressbar
        m_ui->progressBar_accu->setFormat("LOW!");

        //set value to lowest
        m_ui->progressBar_accu->setValue(0);
    }
    else
    {
        //battery is very low
        if(value < Constants::VOLT_LOW_WARN)
        {
            //warn user
            sendTextOut("Voltage very low, replace battery now!");

        //battery is running low
        }
        else if(value < Constants::VOLT_LOW_NORM)
        {
            //warn user
            sendTextOut("Voltage low, consider replacing battery!");
        }

        //set progressbar to show percentage
        m_ui->progressBar_accu->setFormat("%p%");

        //set current voltage as percentage of accu power
        m_ui->progressBar_accu->setValue((value - Constants::VOLT_MIN) * 100 / (Constants::VOLT_MAX - Constants::VOLT_MIN));
    }
}

//writes into the textarea at the left
void MainWindow::sendTextOut(QString str)
{
    //initilaize variables
    QString out = QString("");

    //check for error (currently used when xbee has no connection to pc)
    if(str == nullptr)
    {
        //trigger emergency button click
        m_ui->button_emergency->click();

        //ignore rest
        return;
    }

    //iterate through every line
    for(int k = Constants::SOLN - 1; k > 0; k--)
    {
        //shift lines one upward
        m_sendstr[k] = m_sendstr[k-1];
    }

    //shift new text into last line
    m_sendstr[0] = str;

    //build new text to show on gui
    for(int k = Constants::SOLN - 1; k >= 0; k--)
    {
        //one after another
        out.append(m_sendstr[k]).append("\n");
    }

    //show text on gui
    m_ui->label_sendText->setText(out);
}

//get data from virtual gamepad
void MainWindow::setVGPData()
{
    //get inputs from virtual gamepad
    m_SI->setDataSet(m_pad->getSurfaceButtonA(),
                   m_pad->getSurfaceButtonB(),
                   m_pad->getSurfaceButtonX(),
                   m_pad->getSurfaceButtonY(),
                   m_pad->getSurfaceButtonBR(),
                   m_pad->getSurfaceButtonBL(),
                   m_pad->getSurfaceDPup(),
                   m_pad->getSurfaceDPdown(),
                   m_pad->getSurfaceDPleft(),
                   m_pad->getSurfaceDPright(),
                   m_pad->getSurfaceJoystickRX(),
                   m_pad->getSurfaceJoystickLX(),
                   m_pad->getSurfaceJoystickRY(),
                   m_pad->getSurfaceJoystickLY(),
                   m_pad->getSurfaceTrigger()
    );

    //check which tab is currently selected
    if(m_ui->tabWidget->currentWidget() == m_ui->tab_virtualGamepad)
    {
        //use gamepad
        m_SI->setUseGP(false);
    } else
    {
        //use virtual gamepad
        m_SI->setUseGP(true);
    }
}

//write the received values from the game pad into the table
void MainWindow::setValuesGPTable(InputDataSet DataSet)
{
    //write data for all buttons
    m_ui->table_gamePad->item(0, 0)->setText(stringTextBGPT(DataSet.getButtonA()));
    m_ui->table_gamePad->item(1, 0)->setText(stringTextBGPT(DataSet.getButtonB()));
    m_ui->table_gamePad->item(2, 0)->setText(stringTextBGPT(DataSet.getButtonX()));
    m_ui->table_gamePad->item(3, 0)->setText(stringTextBGPT(DataSet.getButtonY()));
    m_ui->table_gamePad->item(4, 0)->setText(stringTextBGPT(DataSet.getButtonR()));
    m_ui->table_gamePad->item(5, 0)->setText(stringTextBGPT(DataSet.getButtonL()));

    //write data for the digipad
    m_ui->table_gamePad->item(6, 0)->setText(stringTextDPGPT(DataSet.getDPdown(),
                                                           DataSet.getDPup(),
                                                           DataSet.getDPright(),
                                                           DataSet.getDPleft()));

    //write data for every axis
    m_ui->table_gamePad->item(7, 0)->setText(QString::number(DataSet.getXLStick()));
    m_ui->table_gamePad->item(8, 0)->setText(QString::number(DataSet.getYLStick()));
    m_ui->table_gamePad->item(9, 0)->setText(QString::number(DataSet.getXRStick()));
    m_ui->table_gamePad->item(10, 0)->setText(QString::number(DataSet.getYRStick()));
    m_ui->table_gamePad->item(11, 0)->setText(QString::number(DataSet.getTrigger()));
}

//virtual game pad reset button pushed
void MainWindow::on_pushButton_reset_clicked()
{
    //reset virtual game pad
    m_pad->resetVGP();
}

//emergency button clicked
void MainWindow::on_button_emergency_clicked()
{
    //start/stop button says stop so we are currently sending data
    if(!m_ui->button_run->text().compare("Stop"))
    {
        //stop sending data
        emit disconnectSender();

        sendTextOut("disconnected");

        //set text of button to start
        m_ui->button_run->setText("Start");

        //reenable tabs
        m_ui->tabWidget->setTabEnabled(!m_ui->tabWidget->currentIndex(), true);
    }

    //set virtual gamepad to it's default state
    m_pad->resetVGP();

    //set status to emergency in red
    setStatus("Emergency", "#FF0000");

    //and send update to gui console thingy
    sendTextOut("Emergency");
}

//set text and colour of status
void MainWindow::setStatus(QString message, QString colour)
{
    //new message running
    if(!message.compare("Running"))
    {
        //shouldn't overwrite old message emergency
        if(!m_status.compare("Emergency"))
        {
            return;
        }
    //message crashed shouldn't be overwritten by message emergency
    }
    else if(!m_status.compare("Crashed") && !message.compare("Emergency"))
    {
        return;
    }

    //create new string with message and colour
    QString temp = tr("<font color = '%1'> %2 </font>");

    //save new message
    m_status = message;

    //and bring it onto the label
    m_ui->label_status->setText(temp.arg(colour, message));
}

//start or stop sending data
void MainWindow::on_button_run_clicked()
{
    //reset virtual gamepad
    m_pad->resetVGP();

    //get current connection state
    if(m_ui->button_run->text().compare("Stop"))
    {            
        emit connectSender();

        //sender is connected button says stop
        m_ui->button_run->setText("Stop");

        //disable other tab
        m_ui->tabWidget->setTabEnabled(!m_ui->tabWidget->currentIndex(), false);
    }
    else
    {
        emit disconnectSender();

        sendTextOut("disconnected");

        //sender isn't connected button says start
        m_ui->button_run->setText("Start");

        //enable other tab
        m_ui->tabWidget->setTabEnabled(!m_ui->tabWidget->currentIndex(), true);
    }
}

//reset the virtual gamepad when the tab was changed
void MainWindow::on_tabWidget_currentChanged(int index)
{
    //trying to change to tab gamepad while gamepad is not connected
    if(index == 0 && !Gamepad::isConnected())
    {
        //throw error message
        sendTextOut("No Gamepad connected!");

        //return to virtual gamepad
        m_ui->tabWidget->setCurrentIndex(1);
        return;
    }

    //reset virtual gamepad
    m_pad->resetVGP();
}

void MainWindow::disconnected(QString reason)
{
    sendTextOut(reason);
    setStatus("Stopped", "#FF0000");

    //sender isn't connected button says start
    m_ui->button_run->setText("Start");

    //enable other tab
    m_ui->tabWidget->setTabEnabled(!m_ui->tabWidget->currentIndex(), true);
}
