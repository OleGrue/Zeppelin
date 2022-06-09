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

#include "inputdataset.h"

//constructor
InputDataSet::InputDataSet()
{
    //initialize every attribute
    initAttributes();
}

//destructor
InputDataSet::~InputDataSet() {}

//set button a
void InputDataSet::setButtonA(bool newVar)
{
    m_buttonA = newVar;
}

//get value of button a
bool InputDataSet::getButtonA()
{
    return m_buttonA;
}

//set button b
void InputDataSet::setButtonB(bool newVar)
{
    m_buttonB = newVar;
}

//get value of button b
bool InputDataSet::getButtonB()
{
    return m_buttonB;
}

//set button x
void InputDataSet::setButtonX(bool newVar)
{
    m_buttonX = newVar;
}

//get value of button x
bool InputDataSet::getButtonX()
{
    return m_buttonX;
}

//set button y
void InputDataSet::setButtonY(bool newVar)
{
    m_buttonY = newVar;
}

//get value of button y
bool InputDataSet::getButtonY()
{
    return m_buttonY;
}

//set right bumper
void InputDataSet::setButtonR(bool newVar)
{
    m_buttonR = newVar;
}

//get value of right bumper
bool InputDataSet::getButtonR()
{
    return m_buttonR;
}

//set left bumper
void InputDataSet::setButtonL(bool newVar)
{
    m_buttonL = newVar;
}

//get value of left bumper
bool InputDataSet::getButtonL()
{
    return m_buttonL;
}

//set directional pad top
void InputDataSet::setDPup(bool newVar)
{
    m_dPup = newVar;
}

//get value of directional pad top
bool InputDataSet::getDPup()
{
    return m_dPup;
}

//set directional pad bottom
void InputDataSet::setDPdown(bool newVar)
{
    m_dPdown = newVar;
}

//get value of directional pad bottom
bool InputDataSet::getDPdown()
{
    return m_dPdown;
}

//set directional pad right
void InputDataSet::setDPright(bool newVar)
{
    m_dPright = newVar;
}

//get value of directional pad right
bool InputDataSet::getDPright()
{
    return m_dPright;
}

//set directional pad left
void InputDataSet::setDPleft(bool newVar)
{
    m_dPleft = newVar;
}

//get value of directional pad left
bool InputDataSet::getDPleft()
{
    return m_dPleft;
}

//set right x-axis
void InputDataSet::setXRStick(int newVar)
{
    m_xRStick = newVar;
}

//get value of right x-axis
int InputDataSet::getXRStick()
{
    return m_xRStick;
}

//set right y-axis
void InputDataSet::setYRStick(int newVar)
{
    m_yRStick = newVar;
}

//get value of right y-axis
int InputDataSet::getYRStick()
{
    return m_yRStick;
}

//set left x-axis
void InputDataSet::setXLStick(int newVar)
{
    m_xLStick = newVar;
}

//get value of left x-axis
int InputDataSet::getXLStick()
{
    return m_xLStick;
}

//set left y-axis
void InputDataSet::setYLStick(int newVar)
{
    m_yLStick = newVar;
}

//get value of left y-axis
int InputDataSet::getYLStick()
{
    return m_yLStick;
}

//set trigger
void InputDataSet::setTrigger(int newVar)
{
    m_trigger = newVar;
}

//get value of trigger
int InputDataSet::getTrigger()
{
    return m_trigger;
} 

//sets Initial attributes
void InputDataSet::initAttributes ()
{
    m_buttonA = false;
    m_buttonB = false;
    m_buttonX = false;
    m_buttonY = false;
    m_buttonR = false;
    m_buttonL = false;
    m_dPup = false;
    m_dPdown = false;
    m_dPright = false;
    m_dPleft = false;
    m_xLStick = 0;
    m_yLStick = 0;
    m_xRStick = 0;
    m_yRStick = 0;
    m_trigger = 0;
}


