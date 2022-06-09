/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>
#include "imagelabel.h"
#include "virtualgamepad.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_main;
    QWidget *widget_statusBar;
    QHBoxLayout *horizontalLayout_statusBar;
    QGridLayout *gridLayout_functions;
    QLabel *label_accu;
    QLabel *label_status;
    QPushButton *button_run;
    QLabel *label_sendText;
    QProgressBar *progressBar_accu;
    QPushButton *button_emergency;
    QTabWidget *tabWidget;
    QWidget *tab_gamepad;
    QHBoxLayout *horizontalLayout_tabGamepad;
    ImageLabel *imageLabel_controller;
    QTableWidget *table_gamePad;
    QWidget *tab_virtualGamepad;
    QGridLayout *gridLayout;
    QPushButton *pushButton_reset;
    VirtualGamePad *virtualGamePad;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1257, 791);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_main = new QGridLayout(centralWidget);
        gridLayout_main->setSpacing(6);
        gridLayout_main->setContentsMargins(11, 11, 11, 11);
        gridLayout_main->setObjectName(QStringLiteral("gridLayout_main"));
        widget_statusBar = new QWidget(centralWidget);
        widget_statusBar->setObjectName(QStringLiteral("widget_statusBar"));
        widget_statusBar->setMinimumSize(QSize(0, 200));
        horizontalLayout_statusBar = new QHBoxLayout(widget_statusBar);
        horizontalLayout_statusBar->setSpacing(6);
        horizontalLayout_statusBar->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_statusBar->setObjectName(QStringLiteral("horizontalLayout_statusBar"));

        gridLayout_main->addWidget(widget_statusBar, 0, 0, 1, 2);

        gridLayout_functions = new QGridLayout();
        gridLayout_functions->setSpacing(6);
        gridLayout_functions->setObjectName(QStringLiteral("gridLayout_functions"));
        label_accu = new QLabel(centralWidget);
        label_accu->setObjectName(QStringLiteral("label_accu"));
        label_accu->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_functions->addWidget(label_accu, 1, 0, 1, 1);

        label_status = new QLabel(centralWidget);
        label_status->setObjectName(QStringLiteral("label_status"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_status->sizePolicy().hasHeightForWidth());
        label_status->setSizePolicy(sizePolicy);
        label_status->setMinimumSize(QSize(120, 25));
        QFont font;
        font.setFamily(QStringLiteral("Arial Black"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_status->setFont(font);
        label_status->setScaledContents(false);

        gridLayout_functions->addWidget(label_status, 0, 2, 1, 1);

        button_run = new QPushButton(centralWidget);
        button_run->setObjectName(QStringLiteral("button_run"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_run->sizePolicy().hasHeightForWidth());
        button_run->setSizePolicy(sizePolicy1);
        button_run->setMinimumSize(QSize(100, 35));
        button_run->setFont(font);

        gridLayout_functions->addWidget(button_run, 0, 0, 1, 2);

        label_sendText = new QLabel(centralWidget);
        label_sendText->setObjectName(QStringLiteral("label_sendText"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_sendText->sizePolicy().hasHeightForWidth());
        label_sendText->setSizePolicy(sizePolicy2);
        label_sendText->setMinimumSize(QSize(0, 120));

        gridLayout_functions->addWidget(label_sendText, 2, 0, 1, 3);

        progressBar_accu = new QProgressBar(centralWidget);
        progressBar_accu->setObjectName(QStringLiteral("progressBar_accu"));
        progressBar_accu->setMinimumSize(QSize(200, 0));
        progressBar_accu->setValue(0);
        progressBar_accu->setInvertedAppearance(false);
        progressBar_accu->setTextDirection(QProgressBar::TopToBottom);

        gridLayout_functions->addWidget(progressBar_accu, 1, 1, 1, 2);

        button_emergency = new QPushButton(centralWidget);
        button_emergency->setObjectName(QStringLiteral("button_emergency"));
        sizePolicy2.setHeightForWidth(button_emergency->sizePolicy().hasHeightForWidth());
        button_emergency->setSizePolicy(sizePolicy2);
        button_emergency->setMinimumSize(QSize(280, 280));
        button_emergency->setMaximumSize(QSize(280, 16777215));
        button_emergency->setSizeIncrement(QSize(0, 0));
        button_emergency->setLayoutDirection(Qt::LeftToRight);
        button_emergency->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"	border: none;\n"
"	outline: none;\n"
"	background-image: url(\":/images/german/emergency_button_released.png\");\n"
"}\n"
"\n"
"QPushButton:pressed \n"
"{\n"
"	background-image: url(\":/images/german/emergency_button_pressed.png\");\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	border: none;\n"
"	outline: none;\n"
"}"));
        button_emergency->setFlat(true);

        gridLayout_functions->addWidget(button_emergency, 3, 0, 1, 3);

        gridLayout_functions->setRowStretch(0, 1);
        gridLayout_functions->setColumnStretch(0, 1);

        gridLayout_main->addLayout(gridLayout_functions, 1, 1, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy3);
        tabWidget->setMinimumSize(QSize(600, 400));
        tabWidget->setTabShape(QTabWidget::Rounded);
        tab_gamepad = new QWidget();
        tab_gamepad->setObjectName(QStringLiteral("tab_gamepad"));
        horizontalLayout_tabGamepad = new QHBoxLayout(tab_gamepad);
        horizontalLayout_tabGamepad->setSpacing(6);
        horizontalLayout_tabGamepad->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_tabGamepad->setObjectName(QStringLiteral("horizontalLayout_tabGamepad"));
        imageLabel_controller = new ImageLabel(tab_gamepad);
        imageLabel_controller->setObjectName(QStringLiteral("imageLabel_controller"));
        sizePolicy2.setHeightForWidth(imageLabel_controller->sizePolicy().hasHeightForWidth());
        imageLabel_controller->setSizePolicy(sizePolicy2);
        imageLabel_controller->setMinimumSize(QSize(400, 400));

        horizontalLayout_tabGamepad->addWidget(imageLabel_controller);

        table_gamePad = new QTableWidget(tab_gamepad);
        if (table_gamePad->columnCount() < 1)
            table_gamePad->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_gamePad->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (table_gamePad->rowCount() < 12)
            table_gamePad->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_gamePad->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_gamePad->setItem(0, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_gamePad->setItem(1, 0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_gamePad->setItem(2, 0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_gamePad->setItem(3, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        table_gamePad->setItem(4, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        table_gamePad->setItem(5, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        table_gamePad->setItem(6, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        table_gamePad->setItem(7, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        table_gamePad->setItem(8, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        table_gamePad->setItem(9, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        table_gamePad->setItem(10, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        table_gamePad->setItem(11, 0, __qtablewidgetitem24);
        table_gamePad->setObjectName(QStringLiteral("table_gamePad"));
        table_gamePad->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(table_gamePad->sizePolicy().hasHeightForWidth());
        table_gamePad->setSizePolicy(sizePolicy4);
        table_gamePad->setMinimumSize(QSize(100, 400));
        table_gamePad->setFrameShape(QFrame::Panel);
        table_gamePad->setFrameShadow(QFrame::Plain);
        table_gamePad->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        table_gamePad->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        table_gamePad->setShowGrid(true);
        table_gamePad->setCornerButtonEnabled(true);
        table_gamePad->setRowCount(12);
        table_gamePad->setColumnCount(1);
        table_gamePad->horizontalHeader()->setVisible(false);
        table_gamePad->horizontalHeader()->setCascadingSectionResizes(true);
        table_gamePad->horizontalHeader()->setDefaultSectionSize(50);
        table_gamePad->horizontalHeader()->setMinimumSectionSize(30);
        table_gamePad->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        table_gamePad->horizontalHeader()->setStretchLastSection(true);
        table_gamePad->verticalHeader()->setCascadingSectionResizes(true);
        table_gamePad->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        table_gamePad->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_tabGamepad->addWidget(table_gamePad);

        horizontalLayout_tabGamepad->setStretch(0, 3);
        horizontalLayout_tabGamepad->setStretch(1, 1);
        tabWidget->addTab(tab_gamepad, QString());
        tab_virtualGamepad = new QWidget();
        tab_virtualGamepad->setObjectName(QStringLiteral("tab_virtualGamepad"));
        gridLayout = new QGridLayout(tab_virtualGamepad);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        pushButton_reset = new QPushButton(tab_virtualGamepad);
        pushButton_reset->setObjectName(QStringLiteral("pushButton_reset"));

        gridLayout->addWidget(pushButton_reset, 0, 1, 1, 1);

        virtualGamePad = new VirtualGamePad(tab_virtualGamepad);
        virtualGamePad->setObjectName(QStringLiteral("virtualGamePad"));
        virtualGamePad->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(virtualGamePad, 1, 0, 1, 2);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 10);
        gridLayout->setColumnStretch(0, 4);
        gridLayout->setColumnStretch(1, 1);
        tabWidget->addTab(tab_virtualGamepad, QString());

        gridLayout_main->addWidget(tabWidget, 1, 0, 1, 1);

        gridLayout_main->setColumnStretch(0, 4);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        label_accu->setText(QApplication::translate("MainWindow", "Akku Ladung:", nullptr));
        label_status->setText(QApplication::translate("MainWindow", "Emergency", nullptr));
        button_run->setText(QApplication::translate("MainWindow", "Start", nullptr));
        label_sendText->setText(QString());
        button_emergency->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = table_gamePad->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Value", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_gamePad->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Button A", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_gamePad->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Button B", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_gamePad->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Button X", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_gamePad->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Button Y", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_gamePad->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Right  Bumper", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_gamePad->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Left Bumper", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_gamePad->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Directional pad", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_gamePad->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Left X-Axis", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table_gamePad->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Left Y-Axis", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = table_gamePad->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "Right X-Axis", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = table_gamePad->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Right Y-Axis", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = table_gamePad->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Trigger", nullptr));

        const bool __sortingEnabled = table_gamePad->isSortingEnabled();
        table_gamePad->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem13 = table_gamePad->item(0, 0);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = table_gamePad->item(1, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = table_gamePad->item(2, 0);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = table_gamePad->item(3, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = table_gamePad->item(4, 0);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = table_gamePad->item(5, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = table_gamePad->item(6, 0);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = table_gamePad->item(7, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = table_gamePad->item(8, 0);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = table_gamePad->item(9, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = table_gamePad->item(10, 0);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = table_gamePad->item(11, 0);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "0", nullptr));
        table_gamePad->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab_gamepad), QApplication::translate("MainWindow", "Gamepad", nullptr));
        pushButton_reset->setText(QApplication::translate("MainWindow", "Werte zur\303\274cksetzen", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_virtualGamepad), QApplication::translate("MainWindow", "Virtuelles Gamepad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
