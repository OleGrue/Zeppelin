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

#include "outputdataset.h"

//constructor
OutputDataSet::OutputDataSet() {
    m_gpio_out = 0;
    m_gpio_enable = 0;
}

//copy function for deep copys
void OutputDataSet::copy(OutputDataSet& original)
{
    //iterate through every output
    for(int i = 0; i < Constants::OUTPUTS; i++)
    {
        //copy value of output
        this->setOutputData(i, original.getOutputData(i));
    }
    this->setGPIOData(original.getGPIOData());
    this->setGPIODir(original.getGPIODir());
}

//get data set
int OutputDataSet::getOutputData(int port)
{
    //only inputs 0 to OUTPUTS are allowed
    if(port >= 0 && port < Constants::OUTPUTS)
    {
        //return value of output
        return m_dataSet[port].getOutputValue();
    }

    //otherwise write error
    std::cout << "Index out of range " << port << std::endl;

    //and return error
    return 0;
}

 void OutputDataSet::setGPIODataPin(int i, bool state)
{
     if(state == true){
         m_gpio_out |= (1<<i);
     }else{
         m_gpio_out &= ~(1<<i);
     }
}

 void OutputDataSet::setGPIOData(int data){
     m_gpio_out = data;
 }


 int OutputDataSet::getGPIOData(){
     return m_gpio_out;
 }


 void OutputDataSet::setGPIODir(int value){
     this->m_gpio_enable = value;
 }

 void OutputDataSet::setGPIODirPin(int i, bool state)
{
     if(state == true){
         m_gpio_enable |= (1<<i);
     }else{
         m_gpio_enable &= ~(1<<i);
     }
}

 //get enable gpio signal
 int OutputDataSet::getGPIODir(){
     return this->m_gpio_enable;
 }


//set a value
void OutputDataSet::setOutputData(int port, int new_var)
{
    //check whether value is in range
    if(new_var > 1000 || new_var < -1000)
    {
        //throw error
        std::cout << "Error " << new_var << " out of bounds!" << std::endl;
        return;
    }
    //set value
    m_dataSet[port].setOutputValue(new_var);
}

char OutputDataSet::getPortType(int port)
{
    if(port >= 0 && port < Constants::OUTPUTS)
    {
        return m_dataSet[port].getType();
    }
    std::cout << "Index out of range " << port << std::endl;
    return 0;
}

void OutputDataSet::setPortType(int port, char new_var)
{
    if(port >= 0 && port < Constants::OUTPUTS)
    {
        m_dataSet[port].setType(new_var);
    } else
    {
        std::cout << "Index out of range " << port << std::endl;
    }
}
