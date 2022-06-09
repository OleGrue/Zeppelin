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

#ifndef OUTPUTDATASET_H
#define OUTPUTDATASET_H

#include "outputdata.h"
#include "constants.h"
#include <iostream>

class OutputDataSet
{
public:
    //constructor
    OutputDataSet();

    //deep copy function
    void copy(OutputDataSet& original);

    //set type of output
    void setPortType(int port, char new_var);

    //set value of output
    void setOutputData(int port, int new_var);

    //get current output
    int getOutputData(int port);

    //get type of output
    char getPortType(int port);

    //get GPIO Output value
    int getGPIOData();

    //set single gpio pin
    void setGPIODataPin(int i, bool state);

    //set all gpio pins at once
    void setGPIOData(int data);


    void setGPIODirPin(int i, bool state);

    //set enable gpio value
    void setGPIODir(int value);

    //get enable gpio signal
    int getGPIODir();

private:
    //membervariables
    OutputData m_dataSet[Constants::OUTPUTS];
    int m_gpio_out;
    int m_gpio_enable;

};

#endif // OUTPUTDATASET_H
