#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Model/dicevalidator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->txfld_CallValueInput->setValidator(new DiceValidator(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_RollDice_clicked()
{
    ui->lbl_ActualDiceValue->setText(mControl.getRandomValue().toQString());
    ui->txfld_CallValueInput->setStyleSheet("QLineEdit { background-color: white}");
    ui->txfld_CallValueInput->setText("");
    if(mControl.isNewGame()){
        ui->lbl_FormerDiceValue->clear();
    }else{
        ui->lbl_FormerDiceValue->setText(mControl.getLastValue().toQString());
    }
    ui->btn_RollDice->setEnabled(false);
    ui->btn_CallValue->setEnabled(true);
}

void MainWindow::on_btn_CallValue_clicked()
{
    QString s  = ui->txfld_CallValueInput->text();
    int val = s.toInt();
    if(val > 0){
        mControl.setCallValue(val);
        ui->txfld_CallValueInput->setStyleSheet("QLineEdit { background-color: green}");
        ui->btn_RollDice->setEnabled(true);
        ui->btn_CallValue->setEnabled(false);
        ui->lbl_ActualDiceValue->setText("");
    }else{
        ui->txfld_CallValueInput->setStyleSheet("QLineEdit { background-color: red}");
    }
}
