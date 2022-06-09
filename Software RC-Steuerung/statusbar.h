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

#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QProgressBar>
#include <QLabel>
#include <QWidget>

class StatusBar : public QWidget {
    //initialize as QObject
    Q_OBJECT

public:
    //constructor
    explicit StatusBar(QLayout *layout, char type, QString label, QWidget *parent = 0);

    //destructor
    virtual ~StatusBar();

    //set text of label
    void setLabelText(QString str);

    //set value of progressbar
    void setProgressbar(int value);

private:
    //graphics
    const QPixmap GRAPHIC_MOTOR;
    const QPixmap GRAPHIC_SERVO;

    //type this status bar is for
    char m_type;

    //image for this statusbar
    QLabel *m_image;

    //progressbar
    QProgressBar *m_progBar;

    //label containing type of this statusbar
    QLabel *m_label;
};

#endif // STATUSBAR_H
