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

#ifndef INPUTGADGET_H
#define INPUTGADGET_H

class InputDataSet
{
public:
    //constructor
    InputDataSet();

    //destructor
    virtual ~InputDataSet();

    //functions to get and set each membervariable
    void setButtonA(bool newVar);
    bool getButtonA(void);
    void setButtonB(bool newVar);
    bool getButtonB(void);
    void setButtonX(bool newVar);
    bool getButtonX(void);
    void setButtonY(bool newVar);
    bool getButtonY(void);
    void setButtonR(bool newVar);
    bool getButtonR(void);
    void setButtonL(bool newVar);
    bool getButtonL(void);
    void setDPup(bool newVar);
    bool getDPup(void);
    void setDPdown(bool newVar);
    bool getDPdown(void);
    void setDPright(bool newVar);
    bool getDPright(void);
    void setDPleft(bool newVar);
    bool getDPleft(void);
    void setXRStick(int newVar);
    int getXRStick(void);
    void setYRStick(int newVar);
    int getYRStick(void);
    void setXLStick(int newVar);
    int getXLStick(void);
    void setYLStick(int newVar);
    int getYLStick(void);
    void setTrigger(int newVar);
    int getTrigger(void);

private:
    //membervariables
    bool m_buttonA;
    bool m_buttonB;
    bool m_buttonX;
    bool m_buttonY;
    bool m_buttonR;
    bool m_buttonL;
    bool m_dPup;
    bool m_dPdown;
    bool m_dPright;
    bool m_dPleft;
    int m_xRStick;
    int m_yRStick;
    int m_xLStick;
    int m_yLStick;
    int m_trigger;

    //initialize attributes
    void initAttributes();
};

#endif // INPUTGADGET_H
