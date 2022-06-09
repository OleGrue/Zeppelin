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

#ifndef OUTPUTDATA_H
#define OUTPUTDATA_H

class OutputData
{
public:
    //constructor
    OutputData();

    //destructor
    virtual ~OutputData();

    //set value of this output
    void setOutputValue(int new_var);

    //set type of this output
    void setType(char new_var);

    //get type of this output
    char getType(void);

    //get value of this output
    int getOutputValue(void);

private:
    //memervariables
    int m_outputValue;
    char m_type;

    //initialize attributes
    void initAttributes();
};

#endif // OUTPUTDATA_H
