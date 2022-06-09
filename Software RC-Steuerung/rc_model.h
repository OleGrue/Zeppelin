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

#ifndef RCMODEL_H
#define RCMODEL_H

#include "inputdataset.h"
#include "outputdataset.h"

class RCModel
{
public:
    //constructor
    RCModel();

    //destructor
    virtual ~RCModel();

private:
    //place objects and variables here

public:
    //calculate output from input
    void calculateOutput(InputDataSet Input, OutputDataSet &Output);

    //initialize outputs
    void setInitialData(OutputDataSet &Output);

    //initialize attributes
    void initAttributes();

    //place further functions here
};

#endif // RCMODEL_H
