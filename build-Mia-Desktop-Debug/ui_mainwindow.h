/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *rolldice;
    QLabel *DiceShow;
    QLabel *LastValue;
    QLineEdit *CallLine;
    QPushButton *callButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        rolldice = new QPushButton(centralWidget);
        rolldice->setObjectName(QStringLiteral("rolldice"));
        rolldice->setGeometry(QRect(150, 150, 100, 27));
        DiceShow = new QLabel(centralWidget);
        DiceShow->setObjectName(QStringLiteral("DiceShow"));
        DiceShow->setGeometry(QRect(187, 30, 26, 17));
        DiceShow->setFrameShape(QFrame::Box);
        DiceShow->setFrameShadow(QFrame::Plain);
        LastValue = new QLabel(centralWidget);
        LastValue->setObjectName(QStringLiteral("LastValue"));
        LastValue->setGeometry(QRect(150, 30, 26, 17));
        LastValue->setFrameShape(QFrame::Box);
        LastValue->setFrameShadow(QFrame::Plain);
        CallLine = new QLineEdit(centralWidget);
        CallLine->setObjectName(QStringLiteral("CallLine"));
        CallLine->setGeometry(QRect(220, 30, 31, 21));
        callButton = new QPushButton(centralWidget);
        callButton->setObjectName(QStringLiteral("callButton"));
        callButton->setGeometry(QRect(270, 150, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        rolldice->setText(QApplication::translate("MainWindow", "Roll", 0));
        DiceShow->setText(QString());
        LastValue->setText(QString());
        callButton->setText(QApplication::translate("MainWindow", "Call", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
