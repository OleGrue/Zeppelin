/********************************************************************************
** Form generated from reading UI file 'virtualgamepad.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIRTUALGAMEPAD_H
#define UI_VIRTUALGAMEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "imagelabel.h"

QT_BEGIN_NAMESPACE

class Ui_VirtualGamePad
{
public:
    QCheckBox *checkBox_buttonLeft;
    QCheckBox *checkBox_buttonRight;
    ImageLabel *image_gamepad;
    QLabel *label_digipad;
    QSlider *horizontalSlider_triggerLeft;
    QLabel *label_leftTrigger;
    QLabel *label_rightTrigger;
    QSlider *horizontalSlider_triggerRight;
    QLabel *label_joystickAxisYLeft;
    QSlider *horizontalSlider_axisYLeft;
    QSlider *horizontalSlider_axisXLeft;
    QLabel *label_joystickAxisXLeft;
    QRadioButton *radioButton_top;
    QRadioButton *radioButton_topLeft;
    QRadioButton *radioButton_topRight;
    QRadioButton *radioButton_left;
    QRadioButton *radioButton_none;
    QRadioButton *radioButton_bottomLeft;
    QRadioButton *radioButton_right;
    QRadioButton *radioButton_bottomRight;
    QRadioButton *radioButton_bottom;
    QCheckBox *checkBox_buttonY;
    QCheckBox *checkBox_buttonB;
    QCheckBox *checkBox_buttonA;
    QCheckBox *checkBox_buttonX;
    QLabel *label_joystickAxisYRight;
    QSlider *horizontalSlider_axisYRight;
    QLabel *label_joystickAxisXRight;
    QSlider *horizontalSlider_axisXRight;

    void setupUi(QWidget *VirtualGamePad)
    {
        if (VirtualGamePad->objectName().isEmpty())
            VirtualGamePad->setObjectName(QStringLiteral("VirtualGamePad"));
        VirtualGamePad->resize(600, 350);
        checkBox_buttonLeft = new QCheckBox(VirtualGamePad);
        checkBox_buttonLeft->setObjectName(QStringLiteral("checkBox_buttonLeft"));
        checkBox_buttonLeft->setGeometry(QRect(20, 110, 89, 17));
        checkBox_buttonLeft->setLayoutDirection(Qt::RightToLeft);
        checkBox_buttonRight = new QCheckBox(VirtualGamePad);
        checkBox_buttonRight->setObjectName(QStringLiteral("checkBox_buttonRight"));
        checkBox_buttonRight->setEnabled(true);
        checkBox_buttonRight->setGeometry(QRect(500, 90, 87, 17));
        checkBox_buttonRight->setCheckable(true);
        image_gamepad = new ImageLabel(VirtualGamePad);
        image_gamepad->setObjectName(QStringLiteral("image_gamepad"));
        image_gamepad->setGeometry(QRect(170, 50, 261, 141));
        label_digipad = new QLabel(VirtualGamePad);
        label_digipad->setObjectName(QStringLiteral("label_digipad"));
        label_digipad->setGeometry(QRect(90, 330, 151, 21));
        label_digipad->setAlignment(Qt::AlignCenter);
        horizontalSlider_triggerLeft = new QSlider(VirtualGamePad);
        horizontalSlider_triggerLeft->setObjectName(QStringLiteral("horizontalSlider_triggerLeft"));
        horizontalSlider_triggerLeft->setGeometry(QRect(31, 40, 84, 22));
        horizontalSlider_triggerLeft->setMinimum(0);
        horizontalSlider_triggerLeft->setMaximum(1000);
        horizontalSlider_triggerLeft->setSingleStep(5);
        horizontalSlider_triggerLeft->setSliderPosition(0);
        horizontalSlider_triggerLeft->setOrientation(Qt::Horizontal);
        horizontalSlider_triggerLeft->setInvertedAppearance(true);
        label_leftTrigger = new QLabel(VirtualGamePad);
        label_leftTrigger->setObjectName(QStringLiteral("label_leftTrigger"));
        label_leftTrigger->setGeometry(QRect(31, 21, 91, 16));
        label_rightTrigger = new QLabel(VirtualGamePad);
        label_rightTrigger->setObjectName(QStringLiteral("label_rightTrigger"));
        label_rightTrigger->setGeometry(QRect(471, 11, 62, 16));
        horizontalSlider_triggerRight = new QSlider(VirtualGamePad);
        horizontalSlider_triggerRight->setObjectName(QStringLiteral("horizontalSlider_triggerRight"));
        horizontalSlider_triggerRight->setGeometry(QRect(471, 30, 84, 22));
        horizontalSlider_triggerRight->setMinimum(-1000);
        horizontalSlider_triggerRight->setMaximum(0);
        horizontalSlider_triggerRight->setSingleStep(5);
        horizontalSlider_triggerRight->setSliderPosition(0);
        horizontalSlider_triggerRight->setOrientation(Qt::Horizontal);
        horizontalSlider_triggerRight->setInvertedAppearance(true);
        label_joystickAxisYLeft = new QLabel(VirtualGamePad);
        label_joystickAxisYLeft->setObjectName(QStringLiteral("label_joystickAxisYLeft"));
        label_joystickAxisYLeft->setGeometry(QRect(21, 151, 87, 16));
        horizontalSlider_axisYLeft = new QSlider(VirtualGamePad);
        horizontalSlider_axisYLeft->setObjectName(QStringLiteral("horizontalSlider_axisYLeft"));
        horizontalSlider_axisYLeft->setGeometry(QRect(21, 170, 84, 22));
        horizontalSlider_axisYLeft->setMinimum(-1000);
        horizontalSlider_axisYLeft->setMaximum(1000);
        horizontalSlider_axisYLeft->setSingleStep(5);
        horizontalSlider_axisYLeft->setOrientation(Qt::Horizontal);
        horizontalSlider_axisXLeft = new QSlider(VirtualGamePad);
        horizontalSlider_axisXLeft->setObjectName(QStringLiteral("horizontalSlider_axisXLeft"));
        horizontalSlider_axisXLeft->setGeometry(QRect(21, 217, 84, 22));
        horizontalSlider_axisXLeft->setMinimum(-1000);
        horizontalSlider_axisXLeft->setMaximum(1000);
        horizontalSlider_axisXLeft->setSingleStep(5);
        horizontalSlider_axisXLeft->setOrientation(Qt::Horizontal);
        label_joystickAxisXLeft = new QLabel(VirtualGamePad);
        label_joystickAxisXLeft->setObjectName(QStringLiteral("label_joystickAxisXLeft"));
        label_joystickAxisXLeft->setGeometry(QRect(21, 198, 87, 16));
        radioButton_top = new QRadioButton(VirtualGamePad);
        radioButton_top->setObjectName(QStringLiteral("radioButton_top"));
        radioButton_top->setGeometry(QRect(179, 241, 16, 16));
        radioButton_topLeft = new QRadioButton(VirtualGamePad);
        radioButton_topLeft->setObjectName(QStringLiteral("radioButton_topLeft"));
        radioButton_topLeft->setGeometry(QRect(160, 260, 16, 16));
        radioButton_topRight = new QRadioButton(VirtualGamePad);
        radioButton_topRight->setObjectName(QStringLiteral("radioButton_topRight"));
        radioButton_topRight->setGeometry(QRect(198, 260, 16, 16));
        radioButton_left = new QRadioButton(VirtualGamePad);
        radioButton_left->setObjectName(QStringLiteral("radioButton_left"));
        radioButton_left->setGeometry(QRect(141, 279, 16, 16));
        radioButton_none = new QRadioButton(VirtualGamePad);
        radioButton_none->setObjectName(QStringLiteral("radioButton_none"));
        radioButton_none->setGeometry(QRect(179, 279, 16, 16));
        radioButton_none->setChecked(true);
        radioButton_bottomLeft = new QRadioButton(VirtualGamePad);
        radioButton_bottomLeft->setObjectName(QStringLiteral("radioButton_bottomLeft"));
        radioButton_bottomLeft->setGeometry(QRect(160, 298, 16, 16));
        radioButton_right = new QRadioButton(VirtualGamePad);
        radioButton_right->setObjectName(QStringLiteral("radioButton_right"));
        radioButton_right->setGeometry(QRect(217, 279, 16, 16));
        radioButton_bottomRight = new QRadioButton(VirtualGamePad);
        radioButton_bottomRight->setObjectName(QStringLiteral("radioButton_bottomRight"));
        radioButton_bottomRight->setGeometry(QRect(198, 298, 16, 16));
        radioButton_bottom = new QRadioButton(VirtualGamePad);
        radioButton_bottom->setObjectName(QStringLiteral("radioButton_bottom"));
        radioButton_bottom->setGeometry(QRect(179, 317, 16, 16));
        checkBox_buttonY = new QCheckBox(VirtualGamePad);
        checkBox_buttonY->setObjectName(QStringLiteral("checkBox_buttonY"));
        checkBox_buttonY->setGeometry(QRect(501, 121, 64, 17));
        checkBox_buttonB = new QCheckBox(VirtualGamePad);
        checkBox_buttonB->setObjectName(QStringLiteral("checkBox_buttonB"));
        checkBox_buttonB->setGeometry(QRect(501, 167, 64, 17));
        checkBox_buttonA = new QCheckBox(VirtualGamePad);
        checkBox_buttonA->setObjectName(QStringLiteral("checkBox_buttonA"));
        checkBox_buttonA->setGeometry(QRect(501, 190, 65, 17));
        checkBox_buttonX = new QCheckBox(VirtualGamePad);
        checkBox_buttonX->setObjectName(QStringLiteral("checkBox_buttonX"));
        checkBox_buttonX->setGeometry(QRect(501, 144, 64, 17));
        label_joystickAxisYRight = new QLabel(VirtualGamePad);
        label_joystickAxisYRight->setObjectName(QStringLiteral("label_joystickAxisYRight"));
        label_joystickAxisYRight->setGeometry(QRect(481, 231, 93, 16));
        horizontalSlider_axisYRight = new QSlider(VirtualGamePad);
        horizontalSlider_axisYRight->setObjectName(QStringLiteral("horizontalSlider_axisYRight"));
        horizontalSlider_axisYRight->setGeometry(QRect(481, 250, 84, 22));
        horizontalSlider_axisYRight->setMinimum(-1000);
        horizontalSlider_axisYRight->setMaximum(1000);
        horizontalSlider_axisYRight->setSingleStep(5);
        horizontalSlider_axisYRight->setOrientation(Qt::Horizontal);
        label_joystickAxisXRight = new QLabel(VirtualGamePad);
        label_joystickAxisXRight->setObjectName(QStringLiteral("label_joystickAxisXRight"));
        label_joystickAxisXRight->setGeometry(QRect(481, 278, 93, 16));
        horizontalSlider_axisXRight = new QSlider(VirtualGamePad);
        horizontalSlider_axisXRight->setObjectName(QStringLiteral("horizontalSlider_axisXRight"));
        horizontalSlider_axisXRight->setGeometry(QRect(481, 297, 84, 22));
        horizontalSlider_axisXRight->setMinimum(-1000);
        horizontalSlider_axisXRight->setMaximum(1000);
        horizontalSlider_axisXRight->setSingleStep(5);
        horizontalSlider_axisXRight->setOrientation(Qt::Horizontal);
        horizontalSlider_triggerLeft->raise();
        label_leftTrigger->raise();
        label_rightTrigger->raise();
        horizontalSlider_triggerRight->raise();
        label_joystickAxisYLeft->raise();
        horizontalSlider_axisYLeft->raise();
        horizontalSlider_axisXLeft->raise();
        label_joystickAxisXLeft->raise();
        radioButton_top->raise();
        radioButton_topLeft->raise();
        radioButton_topRight->raise();
        radioButton_left->raise();
        radioButton_none->raise();
        radioButton_bottomLeft->raise();
        radioButton_right->raise();
        radioButton_bottomRight->raise();
        radioButton_bottom->raise();
        checkBox_buttonY->raise();
        checkBox_buttonB->raise();
        checkBox_buttonA->raise();
        checkBox_buttonX->raise();
        label_joystickAxisYRight->raise();
        horizontalSlider_axisYRight->raise();
        label_joystickAxisXRight->raise();
        horizontalSlider_axisXRight->raise();
        checkBox_buttonLeft->raise();
        image_gamepad->raise();
        checkBox_buttonRight->raise();
        label_digipad->raise();

        retranslateUi(VirtualGamePad);

        QMetaObject::connectSlotsByName(VirtualGamePad);
    } // setupUi

    void retranslateUi(QWidget *VirtualGamePad)
    {
        VirtualGamePad->setWindowTitle(QApplication::translate("VirtualGamePad", "Form", nullptr));
        checkBox_buttonLeft->setText(QApplication::translate("VirtualGamePad", "Left Bumper", nullptr));
        checkBox_buttonRight->setText(QApplication::translate("VirtualGamePad", "Right Bumper", nullptr));
        label_digipad->setText(QApplication::translate("VirtualGamePad", "Directional pad: bottom right", nullptr));
        label_leftTrigger->setText(QApplication::translate("VirtualGamePad", "Left Trigger: -1000", nullptr));
        label_rightTrigger->setText(QApplication::translate("VirtualGamePad", "Right Trigger", nullptr));
        label_joystickAxisYLeft->setText(QApplication::translate("VirtualGamePad", "Left Y-Axis: -1000", nullptr));
        label_joystickAxisXLeft->setText(QApplication::translate("VirtualGamePad", "Left X-Axis: -1000", nullptr));
        radioButton_top->setText(QString());
        radioButton_topLeft->setText(QString());
        radioButton_topRight->setText(QString());
        radioButton_left->setText(QString());
        radioButton_none->setText(QString());
        radioButton_bottomLeft->setText(QString());
        radioButton_right->setText(QString());
        radioButton_bottomRight->setText(QString());
        radioButton_bottom->setText(QString());
        checkBox_buttonY->setText(QApplication::translate("VirtualGamePad", "Button Y", nullptr));
        checkBox_buttonB->setText(QApplication::translate("VirtualGamePad", "Button B", nullptr));
        checkBox_buttonA->setText(QApplication::translate("VirtualGamePad", "Button A", nullptr));
        checkBox_buttonX->setText(QApplication::translate("VirtualGamePad", "Button X", nullptr));
        label_joystickAxisYRight->setText(QApplication::translate("VirtualGamePad", "Right Y-Axis: -1000", nullptr));
        label_joystickAxisXRight->setText(QApplication::translate("VirtualGamePad", "Right X-Axis: -1000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VirtualGamePad: public Ui_VirtualGamePad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIRTUALGAMEPAD_H
