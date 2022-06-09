#-------------------------------------------------
#
# Project created by QtCreator
#
#-------------------------------------------------
#***********************************************************************************************
# Copyright (C) 2014
#
# Authors:
# Till Staude
# Julian Engelskirchen
#
# The "RC-Steuerung"-programm is free software: you can redistribute it
# and/or modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation, either version 3 of the License,
# or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
# without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
# See the GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
#***********************************************************************************************/

QT += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -L"$$PWD/SFML/lib" -L"$$PWD/SFML/bin"

CONFIG(release, debug|release): LIBS += -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-window -lsfml-system

TARGET = RCModel_V3_0
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp \
        mainwindow.cpp \
        loopthread.cpp \
        rc_model.cpp \
        statusbar.cpp \
        sender.cpp \
        gamepad.cpp \
        outputdata.cpp \
        surfaceinput.cpp \
        outputdataset.cpp \
        inputdataset.cpp \
        imagelabel.cpp \
        virtualgamepad.cpp

HEADERS += mainwindow.h\
        loopthread.h\
        rc_model.h \
        statusbar.h \
        sender.h \
        outputdata.h \
        surfaceinput.h \
        gamepad.h \
        outputdataset.h \
        constants.h \
        inputdataset.h \
        imagelabel.h \
        virtualgamepad.h

FORMS += mainwindow.ui \
        virtualgamepad.ui

RESOURCES += \
        resources.qrc

INCLUDEPATH += SFML
INCLUDEPATH += SFML/include/
DEPENDPATH += SFML

DISTFILES +=




