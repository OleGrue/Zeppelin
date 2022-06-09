/************************************************************************************************
 * Copyright (C) 2016
 *
 * Authors:
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

#include "virtualgamepad.h"
#include "ui_virtualgamepad.h"

//constructor
VirtualGamePad::VirtualGamePad(QWidget *parent) :
    QWidget(parent), m_ui(new Ui::VirtualGamePad),
    m_pointLeftXAxis(QPoint(0, 46)), m_pointLeftYAxis(QPoint(0, 70)),
    m_pointRightXAxis(QPoint(92, 73)), m_pointRightYAxis(QPoint(92, 96)),
    m_pointLeftBumper(QPoint(6, 21)), m_pointRightBumper(QPoint(92, 21)),
    m_pointLeftTrigger(QPoint(16, 0)), m_pointRightTrigger(QPoint(77, 0)),
    m_pointButtonA(QPoint(100, 31)), m_pointButtonB(QPoint(100, 41)),
    m_pointButtonX(QPoint(100, 51)), m_pointButtonY(QPoint(100, 61)),
    m_pointDirectionalPad(QPoint(35, 100))
{      
    //initialize gui
    m_ui->setupUi(this);

    //load image
    m_ui->image_gamepad->setPixmap(QPixmap(":/images/german/XBox-360-Controller-plain.png"));
}

//destructor
VirtualGamePad::~VirtualGamePad()
{
    delete m_ui;
}

//resize handling
void VirtualGamePad::resizeEvent(QResizeEvent* evt)
{   
    evt->accept();

    //get new size
    QSize size = evt->size();    
    int width = size.width();
    int height = size.height();

    //calculate parameters
    int min = width < height ? width : height;
    int widthPic;
    int heightPic;

    if(13 * width > 25 * height)
    {
        heightPic = height * 0.6;
        widthPic = heightPic * 25 / 13;
    }
    else
    {
        widthPic = width * 0.6;
        heightPic = widthPic * 13 / 25;
    }

    //scale image
    m_pic.moveTo(width / 2 - widthPic / 2, height / 2 - heightPic / 2 - height * 0.1);
    m_pic.setWidth(widthPic);
    m_pic.setHeight(heightPic);

    //left axis
    QRect leftXAxis = QRect(leftScale(m_pointLeftXAxis) - width * 0.2,
                            topScale(m_pointLeftXAxis) - height * 0.03,
                            width * 0.2 - 5, height * 0.06);

    QRect leftYAxis = QRect(leftScale(m_pointLeftYAxis) - width * 0.2,
                            topScale(m_pointLeftYAxis) - height * 0.03,
                            width * 0.2 - 5, height * 0.06);

    QRect leftXAxisText = QRect(leftScale(m_pointLeftXAxis) - width * 0.2,
                                topScale(m_pointLeftXAxis) - 30 - height * 0.015,
                                width * 0.2 - 5, 30);

    QRect leftYAxisText = QRect(leftScale(m_pointLeftYAxis) - width * 0.2,
                                topScale(m_pointLeftYAxis) - 30 - height * 0.015,
                                width * 0.2 - 5, 30);

    //right axis
    QRect rightXAxis = QRect(leftScale(m_pointRightXAxis) + 5,
                             topScale(m_pointRightXAxis) - height * 0.03,
                             width * 0.2 - 5, height * 0.06);

    QRect rightYAxis = QRect(leftScale(m_pointRightYAxis) + 5,
                             topScale(m_pointRightYAxis) - height * 0.03,
                             width * 0.2 - 5, height * 0.06);

    QRect rightXAxisText = QRect(leftScale(m_pointRightXAxis) + 5,
                                 topScale(m_pointRightXAxis) + height * 0.015,
                                 width * 0.2 - 5, 30);

    QRect rightYAxisText = QRect(leftScale(m_pointRightYAxis) + 5,
                                 topScale(m_pointRightYAxis) + height * 0.015,
                                 width * 0.2 - 5, 30);

    //bumper
    QRect leftBumper = QRect(leftScale(m_pointLeftBumper) - width * 0.1 - 5,
                             topScale(m_pointLeftBumper) - 15,
                             width * 0.1, 30);

    QRect rightBumper = QRect(leftScale(m_pointRightBumper) + 5,
                              topScale(m_pointRightBumper) - 15,
                              width * 0.1, 30);

    //trigger
    QRect leftTrigger = QRect(leftScale(m_pointLeftTrigger) - width * 0.2,
                              topScale(m_pointLeftTrigger) - height * 0.03,
                              width * 0.2 - 5, height * 0.06);

    QRect leftTriggerText = QRect(leftScale(m_pointLeftTrigger) - width * 0.2,
                                  topScale(m_pointLeftTrigger) - 30 - height * 0.03,
                                  width * 0.2 - 5, 30);

    QRect rightTrigger = QRect(leftScale(m_pointRightTrigger) + 5,
                               topScale(m_pointRightTrigger) - height * 0.03,
                               width * 0.2, height * 0.06);

    QRect rightTriggerText = QRect(leftScale(m_pointRightTrigger) + 5,
                                   topScale(m_pointRightTrigger) - 30 - height * 0.03,
                                   width * 0.2, 30);

    //buttons
    QRect buttonA = QRect(leftScale(m_pointButtonY) + 5,
                          topScale(m_pointButtonY) - 15,
                          width * 0.1, 30);

    QRect buttonB = QRect(leftScale(m_pointButtonX) + 5,
                          topScale(m_pointButtonX) - 15,
                          width * 0.1, 30);

    QRect buttonX = QRect(leftScale(m_pointButtonB) + 5,
                          topScale(m_pointButtonB) - 15,
                          width * 0.1, 30);

    QRect buttonY = QRect(leftScale(m_pointButtonA) + 5,
                          topScale(m_pointButtonA) - 15,
                          width * 0.1, 30);

    //directionalpad
    QRect rButtonMid = QRect(leftScale(m_pointDirectionalPad) - min * 0.025,
                             topScale(m_pointDirectionalPad) + height * 0.1,
                             min * 0.05, min * 0.05);

    QRect rButtonLeft = QRect(leftScale(m_pointDirectionalPad) - min * 0.125,
                              topScale(m_pointDirectionalPad) + height * 0.1,
                              min * 0.05, min * 0.05);

    QRect rButtonRight = QRect(leftScale(m_pointDirectionalPad) + min * 0.075,
                               topScale(m_pointDirectionalPad) + height * 0.1,
                               min * 0.05, min * 0.05);

    QRect rButtonTop = QRect(leftScale(m_pointDirectionalPad) - min * 0.025,
                             topScale(m_pointDirectionalPad),
                             min * 0.05, min * 0.05);

    QRect rButtonBottom = QRect(leftScale(m_pointDirectionalPad) - min * 0.025,
                                topScale(m_pointDirectionalPad) + height * 0.2,
                                min * 0.05, min * 0.05);

    QRect rButtonTopLeft = QRect(leftScale(m_pointDirectionalPad) - min * 0.075,
                                 topScale(m_pointDirectionalPad) + height * 0.05,
                                 min * 0.05, min * 0.05);

    QRect rButtonTopRight = QRect(leftScale(m_pointDirectionalPad) + min * 0.025,
                                  topScale(m_pointDirectionalPad) + height * 0.05,
                                  min * 0.05, min * 0.05);

    QRect rButtonBottomLeft = QRect(leftScale(m_pointDirectionalPad) - min * 0.075,
                                    topScale(m_pointDirectionalPad) + height * 0.15,
                                    min * 0.05, min * 0.05);

    QRect rButtonBottomRight = QRect(leftScale(m_pointDirectionalPad) + min * 0.025,
                                     topScale(m_pointDirectionalPad) + height * 0.15,
                                     min * 0.05, min * 0.05);

    QRect directionalPadText = QRect(leftScale(m_pointDirectionalPad) - width * 0.1,
                                     topScale(m_pointDirectionalPad) + height * 0.2 + min * 0.05,
                                     width * 0.2, 30);

    //picture
    m_ui->image_gamepad->setGeometry(m_pic);

    //left axis
    m_ui->horizontalSlider_axisXLeft->setGeometry(leftXAxis);
    m_ui->horizontalSlider_axisYLeft->setGeometry(leftYAxis);
    m_ui->label_joystickAxisXLeft->setGeometry(leftXAxisText);
    m_ui->label_joystickAxisYLeft->setGeometry(leftYAxisText);

    //right axis
    m_ui->horizontalSlider_axisXRight->setGeometry(rightXAxis);
    m_ui->horizontalSlider_axisYRight->setGeometry(rightYAxis);
    m_ui->label_joystickAxisXRight->setGeometry(rightXAxisText);
    m_ui->label_joystickAxisYRight->setGeometry(rightYAxisText);

    //trigger
    m_ui->horizontalSlider_triggerLeft->setGeometry(leftTrigger);
    m_ui->label_leftTrigger->setGeometry(leftTriggerText);
    m_ui->horizontalSlider_triggerRight->setGeometry(rightTrigger);
    m_ui->label_rightTrigger->setGeometry(rightTriggerText);

    //bumper
    m_ui->checkBox_buttonLeft->setGeometry(leftBumper);
    m_ui->checkBox_buttonRight->setGeometry(rightBumper);

    //buttons
    m_ui->checkBox_buttonA->setGeometry(buttonA);
    m_ui->checkBox_buttonB->setGeometry(buttonB);
    m_ui->checkBox_buttonX->setGeometry(buttonX);
    m_ui->checkBox_buttonY->setGeometry(buttonY);

    //directional pad
    m_ui->radioButton_none->setGeometry(rButtonMid);
    m_ui->radioButton_left->setGeometry(rButtonLeft);
    m_ui->radioButton_right->setGeometry(rButtonRight);
    m_ui->radioButton_top->setGeometry(rButtonTop);
    m_ui->radioButton_bottom->setGeometry(rButtonBottom);
    m_ui->radioButton_topLeft->setGeometry(rButtonTopLeft);
    m_ui->radioButton_topRight->setGeometry(rButtonTopRight);
    m_ui->radioButton_bottomLeft->setGeometry(rButtonBottomLeft);
    m_ui->radioButton_bottomRight->setGeometry(rButtonBottomRight);
    m_ui->label_digipad->setGeometry(directionalPadText);
}

//calculates the left side relative to the image
int VirtualGamePad::leftScale(const QPoint& p)
{
    return m_pic.left() + m_pic.width() * p.x() / 100;
}

//calculates the top side relative to the image
int VirtualGamePad::topScale(const QPoint& p)
{
    return m_pic.top() + m_pic.height() * p.y() / 100;
}

//set everything from the virtual gamepad to its default state
void VirtualGamePad::resetVGP()
{
    //set all sliders to zero
    m_ui->horizontalSlider_axisXLeft->setValue(0);
    m_ui->horizontalSlider_axisXRight->setValue(0);
    m_ui->horizontalSlider_axisYLeft->setValue(0);
    m_ui->horizontalSlider_axisYRight->setValue(0);
    m_ui->horizontalSlider_triggerLeft->setValue(0);
    m_ui->horizontalSlider_triggerRight->setValue(0);

    //set none select button to true
    m_ui->radioButton_none->setChecked(true);

    //disable all button checkboxes
    m_ui->checkBox_buttonA->setChecked(false);
    m_ui->checkBox_buttonB->setChecked(false);
    m_ui->checkBox_buttonX->setChecked(false);
    m_ui->checkBox_buttonY->setChecked(false);
    m_ui->checkBox_buttonLeft->setChecked(false);
    m_ui->checkBox_buttonRight->setChecked(false);

    //update virtual game pad to show values
    updateVGPValues();
}

//updates all virtual gamepad values
void VirtualGamePad::updateVGPValues()
{
    //get value off slider for left x axis and append the value to the label
    int value = m_ui->horizontalSlider_axisXLeft->value();
    QString labeltext = "Left X-Axis: ";
    labeltext.append(QString("%1").arg(value));
    m_ui->label_joystickAxisXLeft->setText(labeltext);

    //get value off slider for left y axis and append the value to the label
    value = m_ui->horizontalSlider_axisYLeft->value();
    labeltext = "Left Y-Axis: ";
    labeltext.append(QString("%1").arg(value));
    m_ui->label_joystickAxisYLeft->setText(labeltext);

    //get value off slider for right x axis and append the value to the label
    value = m_ui->horizontalSlider_axisXRight->value();
    labeltext = "Right X-Axis: ";
    labeltext.append(QString("%1").arg(value));
    m_ui->label_joystickAxisXRight->setText(labeltext);

    //get value off slider for right y axis and append the value to the label
    value = m_ui->horizontalSlider_axisYRight->value();
    labeltext = "Right Y-Axis: ";
    labeltext.append(QString("%1").arg(value));
    m_ui->label_joystickAxisYRight->setText(labeltext);

    //get value from right trigger and add to the value of right trigger
    value = m_ui->horizontalSlider_triggerRight->value();
    value += m_ui->horizontalSlider_triggerLeft->value();

    //append calculated value to left trigger label
    labeltext = "Left Trigger: ";
    labeltext.append(QString("%1").arg(value));
    m_ui->label_leftTrigger->setText(labeltext);

    //and append calculated value to right trigger label
    labeltext = "Right Trigger: ";
    labeltext.append(QString("%1").arg(value));
    m_ui->label_rightTrigger->setText(labeltext);

    //calculate label text of digipad
    labeltext = "Directional pad: ";
    if(m_ui->radioButton_top->isChecked())
    {
        labeltext.append("top");
    }
    else if(m_ui->radioButton_topRight->isChecked())
    {
        labeltext.append("top right");
    }
    else if(m_ui->radioButton_right->isChecked())
    {
        labeltext.append("right");
    }
    else if(m_ui->radioButton_bottomRight->isChecked())
    {
        labeltext.append("bottom right");
    }
    else if(m_ui->radioButton_bottom->isChecked())
    {
        labeltext.append("bottom");
    }
    else if(m_ui->radioButton_bottomLeft->isChecked())
    {
        labeltext.append("bottom left");
    }
    else if(m_ui->radioButton_left->isChecked())
    {
        labeltext.append("left");
    }
    else if(m_ui->radioButton_topLeft->isChecked())
    {
        labeltext.append("top left");
    }
    else
    {
        labeltext.append("none");
    }

    //set label text of digipad
    m_ui->label_digipad->setText(labeltext);
}

//get state of checkbox for button a
bool VirtualGamePad::getSurfaceButtonA()
{
    return m_ui->checkBox_buttonA->isChecked();
}

//get state of checkbox for button b
bool VirtualGamePad::getSurfaceButtonB()
{
    return m_ui->checkBox_buttonB->isChecked();
}

//get state of checkbox for button x
bool VirtualGamePad::getSurfaceButtonX()
{
    return m_ui->checkBox_buttonX->isChecked();
}

//get state of checkbox for button y
bool VirtualGamePad::getSurfaceButtonY()
{
    return m_ui->checkBox_buttonY->isChecked();
}

//get state of checkbox for right button
bool VirtualGamePad::getSurfaceButtonBR()
{
    return m_ui->checkBox_buttonRight->isChecked();
}

//get state of checkbox for left button
bool VirtualGamePad::getSurfaceButtonBL()
{
    return m_ui->checkBox_buttonLeft->isChecked();
}

//get value of left x axis slider
int VirtualGamePad::getSurfaceJoystickLX()
{
    return m_ui->horizontalSlider_axisXLeft->value();
}

//get value of left y axis slider
int VirtualGamePad::getSurfaceJoystickLY()
{
    return m_ui->horizontalSlider_axisYLeft->value();
}

//get value of right x axis slider
int VirtualGamePad::getSurfaceJoystickRX()
{
    return m_ui->horizontalSlider_axisXRight->value();
}

//get value of right y axis slider
int VirtualGamePad::getSurfaceJoystickRY()
{
    return m_ui->horizontalSlider_axisYRight->value();
}

//get value of both trigger sliders merged
int VirtualGamePad::getSurfaceTrigger()
{
    return (m_ui->horizontalSlider_triggerLeft->value() + m_ui->horizontalSlider_triggerRight->value());
}

//calculate whether up on digipad is pressed
bool VirtualGamePad::getSurfaceDPup()
{
    return (m_ui->radioButton_top->isChecked() ||
            m_ui->radioButton_topLeft->isChecked() ||
            m_ui->radioButton_topRight->isChecked()
            );

}

//calculate whether down on digipad is pressed
bool VirtualGamePad::getSurfaceDPdown()
{
    return(m_ui->radioButton_bottom->isChecked() ||
           m_ui->radioButton_bottomLeft->isChecked() ||
           m_ui->radioButton_bottomRight->isChecked()
           );
}

//calculate whether right on digipad is pressed
bool VirtualGamePad::getSurfaceDPright()
{
    return(m_ui->radioButton_right->isChecked() ||
           m_ui->radioButton_topRight->isChecked() ||
           m_ui->radioButton_bottomRight->isChecked()
           );
}

//calculate whether left on digipad is pressed
bool VirtualGamePad::getSurfaceDPleft()
{
    return(m_ui->radioButton_left->isChecked() ||
           m_ui->radioButton_topLeft->isChecked() ||
           m_ui->radioButton_bottomLeft->isChecked()
           );
}

//radio button top clicked
void VirtualGamePad::on_radioButton_top_clicked()
{
    updateVGPValues();
}

//radio button top right clicked
void VirtualGamePad::on_radioButton_topRight_clicked()
{
    updateVGPValues();
}

//radio button right clicked
void VirtualGamePad::on_radioButton_right_clicked()
{
    updateVGPValues();
}

//radio button bottom right clicked
void VirtualGamePad::on_radioButton_bottomRight_clicked()
{
    updateVGPValues();
}

//radio button bottom clicked
void VirtualGamePad::on_radioButton_bottom_clicked()
{
    updateVGPValues();
}

//radio button bottom left clicked
void VirtualGamePad::on_radioButton_bottomLeft_clicked()
{
    updateVGPValues();
}

//radio button left clicked
void VirtualGamePad::on_radioButton_left_clicked()
{
    updateVGPValues();
}

//radio button top left clicked
void VirtualGamePad::on_radioButton_topLeft_clicked()
{
    updateVGPValues();
}

//radio button none clicked
void VirtualGamePad::on_radioButton_none_clicked()
{
    updateVGPValues();
}
