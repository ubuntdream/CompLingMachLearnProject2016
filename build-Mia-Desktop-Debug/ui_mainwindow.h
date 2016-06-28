/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListView *lv_Log;
    QLabel *label_4;
    QLabel *label_11;
    QLabel *label_12;
    QPushButton *btn_ShowResult;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *Player_1_Name;
    QLabel *Player_2_Name;
    QLabel *Player_3_Name;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_16;
    QVBoxLayout *verticalLayout_2;
    QLabel *Player_1_Life;
    QLabel *Player_2_Life;
    QLabel *Player_3_Life;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_17;
    QVBoxLayout *verticalLayout_3;
    QLabel *Player_1_Win;
    QLabel *Player_2_Win;
    QLabel *Player_3_Win;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(768, 537);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_RollDice = new QPushButton(centralWidget);
        btn_RollDice->setObjectName(QStringLiteral("btn_RollDice"));
        btn_RollDice->setGeometry(QRect(420, 160, 100, 27));
        lbl_ActualDiceValue = new QLabel(centralWidget);
        lbl_ActualDiceValue->setObjectName(QStringLiteral("lbl_ActualDiceValue"));
        lbl_ActualDiceValue->setGeometry(QRect(600, 20, 41, 17));
        lbl_ActualDiceValue->setFrameShape(QFrame::Box);
        lbl_ActualDiceValue->setFrameShadow(QFrame::Plain);
        lbl_FormerDiceValue = new QLabel(centralWidget);
        lbl_FormerDiceValue->setObjectName(QStringLiteral("lbl_FormerDiceValue"));
        lbl_FormerDiceValue->setGeometry(QRect(600, 50, 41, 17));
        lbl_FormerDiceValue->setFrameShape(QFrame::Box);
        lbl_FormerDiceValue->setFrameShadow(QFrame::Plain);
        txfld_CallValueInput = new QLineEdit(centralWidget);
        txfld_CallValueInput->setObjectName(QStringLiteral("txfld_CallValueInput"));
        txfld_CallValueInput->setGeometry(QRect(600, 110, 41, 21));
        btn_CallValue = new QPushButton(centralWidget);
        btn_CallValue->setObjectName(QStringLiteral("btn_CallValue"));
        btn_CallValue->setGeometry(QRect(660, 160, 99, 27));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 50, 141, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(450, 20, 131, 21));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(450, 110, 64, 15));
        lv_Log = new QListView(centralWidget);
        lv_Log->setObjectName(QStringLiteral("lv_Log"));
        lv_Log->setGeometry(QRect(10, 30, 391, 451));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 0, 111, 31));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(14);
        label_4->setFont(font);
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(430, 240, 101, 21));
        label_11->setFont(font);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(450, 90, 64, 15));
        btn_ShowResult = new QPushButton(centralWidget);
        btn_ShowResult->setObjectName(QStringLiteral("btn_ShowResult"));
        btn_ShowResult->setGeometry(QRect(530, 160, 121, 27));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(410, 70, 361, 20));
        line->setLineWidth(2);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(393, -10, 41, 481));
        line_2->setLineWidth(2);
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(410, -10, 361, 20));
        line_3->setFrameShadow(QFrame::Raised);
        line_3->setLineWidth(2);
        line_3->setFrameShape(QFrame::HLine);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(410, 210, 351, 20));
        line_4->setLineWidth(2);
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(430, 270, 311, 115));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        Player_1_Name = new QLabel(layoutWidget);
        Player_1_Name->setObjectName(QStringLiteral("Player_1_Name"));

        verticalLayout->addWidget(Player_1_Name);

        Player_2_Name = new QLabel(layoutWidget);
        Player_2_Name->setObjectName(QStringLiteral("Player_2_Name"));

        verticalLayout->addWidget(Player_2_Name);

        Player_3_Name = new QLabel(layoutWidget);
        Player_3_Name->setObjectName(QStringLiteral("Player_3_Name"));

        verticalLayout->addWidget(Player_3_Name);


        verticalLayout_6->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_16 = new QLabel(layoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_5->addWidget(label_16);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        Player_1_Life = new QLabel(layoutWidget);
        Player_1_Life->setObjectName(QStringLiteral("Player_1_Life"));

        verticalLayout_2->addWidget(Player_1_Life);

        Player_2_Life = new QLabel(layoutWidget);
        Player_2_Life->setObjectName(QStringLiteral("Player_2_Life"));

        verticalLayout_2->addWidget(Player_2_Life);

        Player_3_Life = new QLabel(layoutWidget);
        Player_3_Life->setObjectName(QStringLiteral("Player_3_Life"));

        verticalLayout_2->addWidget(Player_3_Life);


        verticalLayout_5->addLayout(verticalLayout_2);


        horizontalLayout->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        label_17 = new QLabel(layoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_4->addWidget(label_17);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        Player_1_Win = new QLabel(layoutWidget);
        Player_1_Win->setObjectName(QStringLiteral("Player_1_Win"));

        verticalLayout_3->addWidget(Player_1_Win);

        Player_2_Win = new QLabel(layoutWidget);
        Player_2_Win->setObjectName(QStringLiteral("Player_2_Win"));

        verticalLayout_3->addWidget(Player_2_Win);

        Player_3_Win = new QLabel(layoutWidget);
        Player_3_Win->setObjectName(QStringLiteral("Player_3_Win"));

        verticalLayout_3->addWidget(Player_3_Win);


        verticalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout->addLayout(verticalLayout_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 768, 25));
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
        label->setText(QApplication::translate("MainWindow", "Former/called value", 0));
        label_2->setText(QApplication::translate("MainWindow", "Actual rolled value", 0));
        label_3->setText(QApplication::translate("MainWindow", "Call input", 0));
        label_4->setText(QApplication::translate("MainWindow", "Log", 0));
        label_11->setText(QApplication::translate("MainWindow", "Statistics", 0));
        label_12->setText(QApplication::translate("MainWindow", "Your turn", 0));
        btn_ShowResult->setText(QApplication::translate("MainWindow", "Show", 0));
        Player_1_Name->setText(QApplication::translate("MainWindow", "Player1", 0));
        Player_2_Name->setText(QApplication::translate("MainWindow", "Player2", 0));
        Player_3_Name->setText(QApplication::translate("MainWindow", "Player3", 0));
        label_16->setText(QApplication::translate("MainWindow", "Lifes", 0));
        Player_1_Life->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        Player_2_Life->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        Player_3_Life->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_17->setText(QApplication::translate("MainWindow", "Wins", 0));
        Player_1_Win->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        Player_2_Win->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        Player_3_Win->setText(QApplication::translate("MainWindow", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
