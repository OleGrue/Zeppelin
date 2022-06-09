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

#include "SurfaceInput.h"
#include "mainwindow.h"

//constructor
SurfaceInput::SurfaceInput() {}

//destructor
SurfaceInput::~SurfaceInput() {}

//get info which gamepad is used
bool SurfaceInput::getUseGP() const
{
    return m_useGP;
}

//set which gamepad is to be used
void SurfaceInput::setUseGP(bool value)
{
    m_useGP = value;
}

//get current input
InputDataSet SurfaceInput::getDataSet()
{
    return m_dataSet;
}

//set current input
void SurfaceInput::setDataSet(bool A,
                              bool B,
                              bool X,
                              bool Y,
                              bool R,
                              bool L,
                              bool DPup,
                              bool DPdown,
                              bool DPleft,
                              bool DPright,
                              short XRStick,
                              short XLStick,
                              short YRStick,
                              short YLStick,
                              short Trigger)
{
    //set buttons to corresponding boolean
    m_dataSet.setButtonA(A);
    m_dataSet.setButtonB(B);
    m_dataSet.setButtonL(L);
    m_dataSet.setButtonR(R);
    m_dataSet.setButtonX(X);
    m_dataSet.setButtonY(Y);
    m_dataSet.setDPdown(DPdown);
    m_dataSet.setDPup(DPup);
    m_dataSet.setDPright(DPright);
    m_dataSet.setDPleft(DPleft);

    //set every axis to corresponding value
    m_dataSet.setXLStick(XLStick);
    m_dataSet.setXRStick(XRStick);
    m_dataSet.setYLStick(YLStick);
    m_dataSet.setYRStick(YRStick);
    m_dataSet.setTrigger(Trigger);
}


