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

#ifndef CONSTANTVARIABLES_H
#define CONSTANTVARIABLES_H

#include <QString>

//static class containing all constants used
class Constants
{
public:
    //SendOutLineNumber
    static const int SOLN = 7;

    //number of outputs at board
    static const int OUTPUTS = 8;

    //values for battery-voltages
    static const int VOLT_MAX = 8400;
    static const int VOLT_MIN = 7000;
    //inform at 30% of max voltage
    static const int VOLT_LOW_NORM = (VOLT_MAX - VOLT_MIN) * 0.3 + VOLT_MIN;
    //warning at 10% of max voltage
    static const int VOLT_LOW_WARN = (VOLT_MAX - VOLT_MIN) * 0.1 + VOLT_MIN;

    //number of outputs used
    static int s_outputsUsed;

    static const QString NAME;
    static const int VENDOR_ID = 1027;

};

#endif // CONSTANTVARIABLES_H
