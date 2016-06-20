#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Model/dicevalidator.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->CallLine->setValidator(new DiceValidator(this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rolldice_clicked()
{
    ui->DiceShow->setText(mControl.getRandomValue().toQString());
    ui->CallLine->setStyleSheet("QLineEdit { background-color: white}");
    ui->CallLine->setText("");
    if(mControl.isNewGame()){
        ui->LastValue->clear();
    }else{
        ui->LastValue->setText(mControl.getLastValue().toQString());
    }
    ui->rolldice->setEnabled(false);
    ui->callButton->setEnabled(true);
}

void MainWindow::on_callButton_clicked()
{
    if(mControl.setCallValue(ui->CallLine->text().toInt())){
        ui->CallLine->setStyleSheet("QLineEdit { background-color: green}");
        ui->rolldice->setEnabled(true);
        ui->callButton->setEnabled(false);
        ui->DiceShow->setText("");
    }else{
        ui->CallLine->setStyleSheet("QLineEdit { background-color: red}");
    }
}
