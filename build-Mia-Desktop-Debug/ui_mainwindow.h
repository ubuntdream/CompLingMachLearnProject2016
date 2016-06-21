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
    QPushButton *btn_RollDice;
    QLabel *lbl_ActualDiceValue;
    QLabel *lbl_FormerDiceValue;
    QLineEdit *txfld_CallValueInput;
    QPushButton *btn_CallValue;
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
        btn_RollDice = new QPushButton(centralWidget);
        btn_RollDice->setObjectName(QStringLiteral("btn_RollDice"));
        btn_RollDice->setGeometry(QRect(150, 150, 100, 27));
        lbl_ActualDiceValue = new QLabel(centralWidget);
        lbl_ActualDiceValue->setObjectName(QStringLiteral("lbl_ActualDiceValue"));
        lbl_ActualDiceValue->setGeometry(QRect(187, 30, 26, 17));
        lbl_ActualDiceValue->setFrameShape(QFrame::Box);
        lbl_ActualDiceValue->setFrameShadow(QFrame::Plain);
        lbl_FormerDiceValue = new QLabel(centralWidget);
        lbl_FormerDiceValue->setObjectName(QStringLiteral("lbl_FormerDiceValue"));
        lbl_FormerDiceValue->setGeometry(QRect(150, 30, 26, 17));
        lbl_FormerDiceValue->setFrameShape(QFrame::Box);
        lbl_FormerDiceValue->setFrameShadow(QFrame::Plain);
        txfld_CallValueInput = new QLineEdit(centralWidget);
        txfld_CallValueInput->setObjectName(QStringLiteral("txfld_CallValueInput"));
        txfld_CallValueInput->setGeometry(QRect(220, 30, 31, 21));
        btn_CallValue = new QPushButton(centralWidget);
        btn_CallValue->setObjectName(QStringLiteral("btn_CallValue"));
        btn_CallValue->setGeometry(QRect(270, 150, 99, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
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
        btn_RollDice->setText(QApplication::translate("MainWindow", "Roll", 0));
        lbl_ActualDiceValue->setText(QString());
        lbl_FormerDiceValue->setText(QString());
        btn_CallValue->setText(QApplication::translate("MainWindow", "Call", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
