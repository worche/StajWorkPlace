/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *comboBox;
    QCustomPlot *plot;
    QLabel *label_2;
    QSplitter *splitter_3;
    QDoubleSpinBox *bt_y;
    QSplitter *splitter;
    QPushButton *pushButton;
    QPushButton *addGrandBt;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1077, 705);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        QFont font;
        font.setPointSize(16);
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        QFont font1;
        font1.setPointSize(22);
        comboBox->setFont(font1);

        gridLayout->addWidget(comboBox, 1, 1, 1, 1);

        plot = new QCustomPlot(centralWidget);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setAutoFillBackground(false);
        plot->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(plot, 0, 0, 1, 5);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 1, 2, 1, 1);

        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Horizontal);
        bt_y = new QDoubleSpinBox(splitter_3);
        bt_y->setObjectName(QStringLiteral("bt_y"));
        QFont font2;
        font2.setPointSize(18);
        bt_y->setFont(font2);
        bt_y->setDecimals(0);
        bt_y->setMinimum(10);
        bt_y->setMaximum(100);
        bt_y->setSingleStep(10);
        bt_y->setValue(50);
        splitter_3->addWidget(bt_y);
        splitter = new QSplitter(splitter_3);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        pushButton = new QPushButton(splitter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        splitter->addWidget(pushButton);
        addGrandBt = new QPushButton(splitter);
        addGrandBt->setObjectName(QStringLiteral("addGrandBt"));
        addGrandBt->setLayoutDirection(Qt::LeftToRight);
        addGrandBt->setCheckable(false);
        splitter->addWidget(addGrandBt);
        label = new QLabel(splitter);
        label->setObjectName(QStringLiteral("label"));
        QFont font3;
        font3.setPointSize(36);
        label->setFont(font3);
        label->setLayoutDirection(Qt::RightToLeft);
        label->setAutoFillBackground(false);
        label->setTextFormat(Qt::AutoText);
        splitter->addWidget(label);
        splitter_3->addWidget(splitter);

        gridLayout->addWidget(splitter_3, 1, 3, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1077, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        comboBox->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_4->setText(QApplication::translate("MainWindow", "Speed:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "100", 0)
         << QApplication::translate("MainWindow", "500", 0)
         << QApplication::translate("MainWindow", "1000", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "Frequency Multiple", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Color\n"
"Change", 0));
        addGrandBt->setText(QApplication::translate("MainWindow", "Add\n"
"Grand", 0));
        label->setText(QApplication::translate("MainWindow", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
