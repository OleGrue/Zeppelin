/************************************************************************************************
 * Copyright (C) 2016
 *
 * Authors:
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

#ifndef VIRTUALGAMEPAD_H
#define VIRTUALGAMEPAD_H

#include <QObject>
#include <QWidget>
#include <QPoint>

namespace Ui {
    class VirtualGamePad;
}

class VirtualGamePad : public QWidget
{
    Q_OBJECT

public:
    explicit VirtualGamePad(QWidget *parent = 0);
    ~VirtualGamePad();

    void resizeEvent(QResizeEvent* evt);

    //reset virtual gamepad
    void resetVGP(void);

    //get virtual gamepad inputs
    bool getSurfaceButtonA(void);
    bool getSurfaceButtonB(void);
    bool getSurfaceButtonX(void);
    bool getSurfaceButtonY(void);
    bool getSurfaceButtonBL(void);
    bool getSurfaceButtonBR(void);
    bool getSurfaceDPup(void);
    bool getSurfaceDPdown(void);
    bool getSurfaceDPright(void);
    bool getSurfaceDPleft(void);
    int getSurfaceJoystickLX(void);
    int getSurfaceJoystickLY(void);
    int getSurfaceJoystickRX(void);
    int getSurfaceJoystickRY(void);
    int getSurfaceTrigger(void);

private:
    Ui::VirtualGamePad* m_ui;
    QRect m_pic;
    //points to relative position on image
    const QPoint m_pointLeftXAxis;
    const QPoint m_pointLeftYAxis;
    const QPoint m_pointRightXAxis;
    const QPoint m_pointRightYAxis;
    const QPoint m_pointLeftBumper;
    const QPoint m_pointRightBumper;
    const QPoint m_pointLeftTrigger;
    const QPoint m_pointRightTrigger;
    const QPoint m_pointButtonA;
    const QPoint m_pointButtonB;
    const QPoint m_pointButtonX;
    const QPoint m_pointButtonY;
    const QPoint m_pointDirectionalPad;

    //scaling methods
    int leftScale(const QPoint& p);
    int topScale(const QPoint& p);

public slots:
    //update virtual gamepad
    void updateVGPValues(void);

private slots:
    //slots connecting to gui
    void on_radioButton_top_clicked(void);
    void on_radioButton_topRight_clicked(void);
    void on_radioButton_right_clicked(void);
    void on_radioButton_bottomRight_clicked(void);
    void on_radioButton_bottom_clicked(void);
    void on_radioButton_bottomLeft_clicked(void);
    void on_radioButton_left_clicked(void);
    void on_radioButton_topLeft_clicked(void);
    void on_radioButton_none_clicked(void);
};

#endif // VIRTUALGAMEPAD_H
