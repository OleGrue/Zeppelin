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

#ifndef GAMEPAD_H
#define GAMEPAD_H

#include "inputdataset.h"
#include "SFML/Window.hpp"

//definitions of buttons
#define BUTTONA     0
#define BUTTONB     1
#define BUTTONX     2
#define BUTTONY     3
#define RBUMPER     4
#define LBUMPER     5
#define BACK        6
#define START       7

//definitions of every axis
#define RIGHTXAXIS sf::Joystick::Axis::U
#define RIGHTYAXIS sf::Joystick::Axis::R
#define LEFTXAXIS sf::Joystick::Axis::U
#define LEFTYAXIS sf::Joystick::Axis::V
#define TRIGGER sf::Joystick::Axis::Z
#define DPADXAXIS sf::Joystick::Axis::PovX
#define DPADYAXIS sf::Joystick::Axis::PovY

class Gamepad
{
public:
    //constructor
    Gamepad();

    //destructor
    virtual ~Gamepad();

    //static bool stating connection
    static bool isConnected();

    //update data of gamepad
    void updateData();

    //get input of gamepad
    InputDataSet getDataSet();

private:
    //membervariables
    InputDataSet m_dataSet;

};


#endif // GAMEPAD_H
