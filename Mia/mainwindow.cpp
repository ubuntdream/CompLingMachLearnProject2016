#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Model/dicevalidator.h"

#include "Control/statistic.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    mControl = new Control(3);
    ui->setupUi(this);
    ui->txfld_CallValueInput->setValidator(new DiceValidator(this));

    appendToLogView("Welcome to the game mia");
    appendToLogView("Roll the dice and figure out if you will say the truth or lie to the next player");
    ui->btn_RollDice->setEnabled(true);
    ui->btn_CallValue->setEnabled(false);
    ui->btn_ShowResult->setEnabled(false);

    setPlayerValue();
    setActivPlayer();

    Statistic tmp;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::appendToLogView(QString s){
    ui->txfld_log->append(s);
}

void MainWindow::on_btn_RollDice_clicked()
{
    ui->lbl_ActualDiceValue->setText(mControl->getRandomValue().toQString());
    if(mControl->isNewGame()){
        ui->lbl_FormerDiceValue->clear();
    }else{
        ui->lbl_FormerDiceValue->setText(mControl->getLastValue().toQString());
    }
    toggleRollCall();
}

void MainWindow::on_btn_CallValue_clicked()
{
    QString s  = ui->txfld_CallValueInput->text();
    int val = s.toInt();

    //Get Some informations
    int apid = mControl->GetActivPlayerID();
    Value diceval = mControl->getOnlyRandomValue();

    if(val > 10 && mControl->Call_is_correct(val)){
        mControl->setCallValue(val);
        toggleRollCall();

        ui->lbl_ActualDiceValue->setText(s);
        ui->txfld_CallValueInput->setStyleSheet("QLineEdit { background-color: white}");
        ui->txfld_CallValueInput->setText("");

        appendToLogView("Player "+QString::number(apid)+": Called "+mControl->getNewValue().toQString()+"(trueth: "+diceval.toQString()+")");

        mControl->NextPlayer();
        setActivPlayer(); // nur UI
    }else{
        //Nicht schön, aber so sieht man, dass eingabe Fasch war
        ui->txfld_CallValueInput->setStyleSheet("QLineEdit { background-color: red}");
    }
}

void MainWindow::toggleRollCall()
{
    if (!ui->btn_CallValue->isEnabled()) {
        ui->btn_RollDice->setEnabled(false);
        ui->btn_ShowResult->setEnabled(false);
        ui->btn_CallValue->setEnabled(true);
        ui->txfld_CallValueInput->setEnabled(true);
    }else{
        ui->btn_RollDice->setEnabled(true);
        ui->btn_ShowResult->setEnabled(true);
        ui->btn_CallValue->setEnabled(false);
        ui->txfld_CallValueInput->setEnabled(false);
    }
}

// Läd nacheinander die einzenen Spieler und blendet ihre Werte ein
void MainWindow::setPlayerValue(){
    Player p = mControl->GetPlayer(0);
    ui->Player_1_Life->setText(QString::number(p.getLife()));
    ui->Player_1_Win->setText(QString::number(p.getWin()));

    p = mControl->GetPlayer(1);
    ui->Player_2_Life->setText(QString::number(p.getLife()));
    ui->Player_2_Win->setText(QString::number(p.getWin()));

    p = mControl->GetPlayer(2);
    ui->Player_3_Life->setText(QString::number(p.getLife()));
    ui->Player_3_Win->setText(QString::number(p.getWin()));
}

// Markiert, welcher Spieler aktuell am Zug ist
void MainWindow::setActivPlayer(){
    int i = mControl->GetActivPlayerID();
    ui->Player_1_Name->setStyleSheet("QLabel { background-color : white};");
    ui->Player_2_Name->setStyleSheet("QLabel { background-color : white};");
    ui->Player_3_Name->setStyleSheet("QLabel { background-color : white};");
    if(i == 0){
        ui->Player_1_Name->setStyleSheet("QLabel { background-color : green};");
    }else if(i == 1){
        ui->Player_2_Name->setStyleSheet("QLabel { background-color : green};");
    }else if(i == 2){
        ui->Player_3_Name->setStyleSheet("QLabel { background-color : green};");
    }
}

void MainWindow::on_btn_ShowResult_clicked()
{
    QString s = mControl->look_at_last_Player();
    appendToLogView(s);
    setPlayerValue();
    mControl->setNewGame();
    ui->btn_ShowResult->setEnabled(false);
}
