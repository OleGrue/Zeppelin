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

#include "statusbar.h"

//constructor
StatusBar::StatusBar(QLayout *layout, char type, QString label, QWidget *parent) :
    QWidget(parent),
    GRAPHIC_MOTOR(QPixmap(":/images/german/brushless-motor.png")),
    GRAPHIC_SERVO(QPixmap(":/images/german/servo.png")),
    m_type(type)
{
    //initialize variables
    QPixmap graphic;
    QString name;
    QString format;
    int maxValue = 0;

    //get type this statusbar should be
    switch(type)
    {
        //this statusbar is for a motor
        case 'm':
            //use motor graphic
            graphic = GRAPHIC_MOTOR;

            //call it motor
            name = "Motor at " + label;

            //set maxvalue to 100%
            maxValue = 100;

            //use value as string with % attached
            format = QString("%v%");
            break;

        //this statusbar is for a servo
        case 's':
            //use servo graphic
            graphic = GRAPHIC_SERVO;

            //call it servo
            name = "Servo at " + label;

            //set maxvalue to 45°
            maxValue = 45;

            //use value as string with ° attached
            format = QString("%v°");
            break;

        //this statusbar has an unknown type
        default:
            //use default values
            graphic = GRAPHIC_MOTOR;
            name = "Default";
            maxValue = 100;
    }

    //initialize labels and progressbar
    m_image = new QLabel;
    m_progBar = new QProgressBar;
    m_label = new QLabel;

    //set maximum height of picture
    m_image->setMaximumHeight(120);

    //align picture at the middle of the statusbar
    m_image->setAlignment(Qt::AlignCenter);

    //set graphic to label
    m_image->setPixmap(graphic.scaled(m_image->size(), Qt::KeepAspectRatio));

    //set text of label
    m_label->setText(name);

    //set maximumvalue of progressbar
    m_progBar->setMaximum(maxValue);

    //set format of progressbar
    m_progBar->setFormat(format);

    //set value of progressbar
    m_progBar->setValue(0);

    //arrange parts of statusbar vertically
    QVBoxLayout *VLayout = new QVBoxLayout;
    VLayout->addWidget(m_image);
    VLayout->addStretch(10);
    VLayout->addWidget(m_progBar);
    VLayout->addStretch(5);
    VLayout->addWidget(m_label);
    VLayout->addStretch(5);

    //add vertical layout to rest of statusbars
    ((QHBoxLayout*)layout)->addLayout(VLayout);
}

//destructor
StatusBar::~StatusBar()
{
    //delete all the objects created on heap
    delete m_image;
    delete m_progBar;
    delete m_label;
}

//set text of label
void StatusBar::setLabelText(QString str)
{
    m_label->setText(str);
}

//set value of progressbar
void StatusBar::setProgressbar(int value)
{
    QString format;

    //if value greater zero
    if(value >= 0)
    {
        //progressbar begins at the left
        m_progBar->setInvertedAppearance(false);
    }
    else if(value < 0)
    {
        //number is negativ, append minus
        format.append("-");

        //progressbar begins at the right
        m_progBar->setInvertedAppearance(true);

        //invert number
        value *= -1;
    }

    //type is servo
    if(m_type == 's')
    {
        //add value and ° to label
        format.append("%v°");

        //divide value by 22 so 1000 is 45°
        m_progBar->setValue(value / 22);
    }
    else
    {
        //add value and % to label
        format.append("%v%");

        //divide value by 10 so 1000 is 100%
        m_progBar->setValue(value / 10);
    }

    //update label of progressbar
    m_progBar->setFormat(format);
}
