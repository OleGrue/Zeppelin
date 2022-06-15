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
#include <iostream>
#include <stdlib.h>

//Global variables
int speed_speed = 0; //defines the general speed of all motors
int up_down = 0;

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

    //wer das liest ist doof
    //screw you Hendik


    //Output.setOutputData(2, 100 - Input.getXRStick());
    //Output.setOutputData(0, 100 - Input.getXRStick()*-1);



    if(Input.getButtonB()){  //increases general speed
        speed_speed = speed_speed + 100;
    }
    if(Input.getButtonX()){  //lowers general speed
        speed_speed = speed_speed - 100;
    }
    if(Input.getButtonY()){  //sets speed to 0
        speed_speed = 0;
    }
    if((Input.getButtonB())&&(Input.getButtonA())){ // increases speed to the max (forward)
        speed_speed = 1000;
    }
    if((Input.getButtonX())&&(Input.getButtonA())){ // increases speed to the max (backward)
        speed_speed = -1000;
    }

    if(speed_speed>1000){ //maxes sure the speed doesnt go over 9000 (1000)
        speed_speed = 1000;
    }

    if(speed_speed<-1000){ //makes sure the speed doesnt go under -1000
        speed_speed = -1000;
    }


    if(Input.getDPright()){ //servo goes up
        up_down = up_down + 100;
    }

    if(Input.getDPleft()){ //servo goes down
        up_down = up_down - 100;
    }

    if(up_down>1000){ //makes sure the servo doesnt go over 45°
        up_down = 1000;
    }

    if(up_down<-1000){ //makes sure the servo doesnt go under -45°
        up_down = -1000;

    }


    if(Input.getDPup()){ //resets servo pitch
        up_down = 0;
    }





    Output. setOutputData(3,up_down); //gives servo commands








    if(Input.getXRStick()>100){  // determines the Speed of the right motor

        float right_input = Input.getXRStick();
        float onek_stick = 1000-right_input;
        float speed_right = onek_stick/1000*speed_speed;

        Output.setOutputData(2, speed_right);  //gives the right motor the correct speed
        Output.setOutputData(1,speed_speed);  //sets the left motor to the normal speed
    }
    else if(Input.getXRStick()<-100){  //determines the speed of the left motor

        float right_input = -Input.getXRStick();
        float onek_stick = 1000-right_input;
        float speed_left = onek_stick/1000*speed_speed;

        Output.setOutputData(1, speed_left);
        Output.setOutputData(2,speed_speed);

    }  //gives the motors their normal speed
    else if(Input.getTrigger()<-50){
        Output.setOutputData(1, speed_speed);
        Output.setOutputData(2,- speed_speed);
    }
    //Powerspiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiin (right)
    else if(Input.getTrigger()>50){
        Output.setOutputData(1,- speed_speed);
        Output.setOutputData(2,speed_speed);
    }
    //Powerspiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiin (left)
    else{
        Output.setOutputData(2,speed_speed);
        Output.setOutputData(1,speed_speed);
   }
}

//This function initializes the outputs. Here you can declare whether there is a motor or a servo
//connected to your output at the circuit board in your airship.
void RCModel::setInitialData(OutputDataSet &Output)
{
    //Was ist an die Ports angeschlossen? e-empty, m-motor, s-servo
    Output.setPortType(0,'e');  //Type Port 0 Kein Alles
    Output.setPortType(1,'m');  //Type Port 1
    Output.setPortType(2,'m');  //Type Port 2
    Output.setPortType(3,'s');  //Type Port 3
    Output.setPortType(4,'s');  //Type Port 4
    Output.setPortType(5,'e');  //Type Port 5 KEin Servo
    Output.setPortType(6,'e');  //Type Port 6
    Output.setPortType(7,'s');  //Type Port 7
}

//This function initializes all attributes and membervariables. It will be called once by the
//constructor.
void RCModel::initAttributes()
{
}

