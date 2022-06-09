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

#include "gamepad.h"

//constructor
Gamepad::Gamepad() {}

//destructor
Gamepad::~Gamepad() {}

//checks whether a joystick is connected
bool Gamepad::isConnected()
{
    //update all joysticks
    sf::Joystick::update();

    //return whether joystick 0 is connected (we will only use that one)
    return sf::Joystick::isConnected(0);
}

//updates the m_dataset
void Gamepad::updateData()
{
    //call update to get a read
    sf::Joystick::update();

    //get the reads for all buttons
    m_dataSet.setButtonA(sf::Joystick::isButtonPressed(0, BUTTONA));
    m_dataSet.setButtonB(sf::Joystick::isButtonPressed(0, BUTTONB));
    m_dataSet.setButtonX(sf::Joystick::isButtonPressed(0, BUTTONX));
    m_dataSet.setButtonY(sf::Joystick::isButtonPressed(0, BUTTONY));
    m_dataSet.setButtonL(sf::Joystick::isButtonPressed(0, RBUMPER));
    m_dataSet.setButtonR(sf::Joystick::isButtonPressed(0, LBUMPER));

    //read data of directionalpad
    m_dataSet.setDPup(sf::Joystick::getAxisPosition(0, DPADXAXIS) > 10);
    m_dataSet.setDPdown(sf::Joystick::getAxisPosition(0, DPADXAXIS) < -10);
    m_dataSet.setDPleft(sf::Joystick::getAxisPosition(0, DPADYAXIS) < -10);
    m_dataSet.setDPright(sf::Joystick::getAxisPosition(0, DPADYAXIS) > 10);

    //get the reads for every axis
    m_dataSet.setXLStick((int) sf::Joystick::getAxisPosition(0, LEFTXAXIS) * 10);
    m_dataSet.setYLStick((int) sf::Joystick::getAxisPosition(0, LEFTYAXIS) * 10);
    m_dataSet.setXRStick((int) sf::Joystick::getAxisPosition(0, RIGHTXAXIS) * 10);
    m_dataSet.setYRStick((int) sf::Joystick::getAxisPosition(0, RIGHTYAXIS) * 10);
    m_dataSet.setTrigger((int) sf::Joystick::getAxisPosition(0, TRIGGER) * 10);
}


// returns the current dataset, containing the information of the last update by setData()
InputDataSet Gamepad::getDataSet()
{
    return m_dataSet;
}



