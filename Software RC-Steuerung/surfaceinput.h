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

#ifndef SURFACEINPUT_H
#define SURFACEINPUT_H

#include "inputdataset.h"

class SurfaceInput
{
public:
    //constructor
    SurfaceInput();

    //destructor
    virtual ~SurfaceInput();

private:
    //saves inputs
    InputDataSet m_dataSet;

    //saves whether gamepad or virtualgamepad is used
    bool m_useGP;

public:
    //get current state of gamepad
    InputDataSet getDataSet();

    //set data set
    void setDataSet(bool A, bool B, bool X, bool Y, bool R, bool L, bool DPup, bool DPdown, bool DPleft, bool DPright, short XRStick, short XLStick, short YRStick, short YLStick, short Trigger);

    //get whether gamepad or virtual gamepad is used
    bool getUseGP() const;

    //set which one to use
    void setUseGP(bool value);
};


#endif // SURFACEINPUT_H
