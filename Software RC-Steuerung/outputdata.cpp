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

#include "outputdata.h"

//constructor
OutputData::OutputData()
{
    initAttributes();
}

//destructor
OutputData::~OutputData() {}

//set value of this object
void OutputData::setOutputValue(int new_var)
{
    m_outputValue = new_var;
}

//get value of this object
int OutputData::getOutputValue()
{
    return m_outputValue;
}

//set type of this output
void OutputData::setType(char new_var)
{
    //is type illegal
    if(new_var != 'm' && new_var != 's')
    {
        //set it to empty
        new_var = 'e';
    }
    //save type
    m_type = new_var;
}

//get type of this output
char OutputData::getType()
{
    return m_type;
} 

//initialize attributes
void OutputData::initAttributes()
{
    m_outputValue = 0;
    m_type = 'e';
}

