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

#include "rc_model.h"



//Constructor
RCModel::RCModel()
{
    //initialize all attributes
    initAttributes();
}

//Destructor
RCModel::~RCModel() {}

//This function will calculate an output from a given input. The input are all buttons and axis from the
//gamepad or virtual gamepad. The output will be send to the airship.
void RCModel::calculateOutput(InputDataSet Input, OutputDataSet &Output)
{

    // Bsp für die Steuerung --> JStick Achsen direkt auf ersten 5 Ports
    //Output.setOutputData(0, Input.getYRStick());
    //Output.setOutputData(2, Input.getXRStick());
    //Output.setOutputData(1, Input.getTrigger());
    //Output.setOutputData(3, Input.getTrigger()*-1);




    Output.setOutputData(2, 100 - Input.getXRStick());
    Output.setOutputData(0, 100 - Input.getXRStick()*-1);



}

//This function initializes the outputs. Here you can declare whether there is a motor or a servo
//connected to your output at the circuit board in your airship.
void RCModel::setInitialData(OutputDataSet &Output)
{
    //Was ist an die Ports angeschlossen? e-empty, m-motor, s-servo
    Output.setPortType(0,'m');  //Type Port 0
    Output.setPortType(1,'s');  //Type Port 1
    Output.setPortType(2,'m');  //Type Port 2
    Output.setPortType(3,'s');  //Type Port 3
    Output.setPortType(4,'m');  //Type Port 4
    Output.setPortType(5,'e');  //Type Port 5
    Output.setPortType(6,'e');  //Type Port 6
    Output.setPortType(7,'s');  //Type Port 7
}

//This function initializes all attributes and membervariables. It will be called once by the
//constructor.
void RCModel::initAttributes()
{
}

