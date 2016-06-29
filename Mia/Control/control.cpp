#include "control.h"

#include <iostream>

// Konstruktor der Klasse
// int anz ist die Anzahl der Spieler die erstellt werden soll

Control::Control(int anz)
{
    std::srand(std::time(NULL));
    mStartGame = true;
    mNewValue = Value();
    mRandomValue = Value();
    mlastValue = Value();

    for(int i = 0; i < anz; i++){
        mPlayers.push_back(*(new Player));
    }
    mActivPlayerID = 0;
}

Control::~Control()
{

}

// Roll two dice and return the value
Value Control::getRandomValue(){
    mlastValue.set(mNewValue);
    mRandomValue.set(rollDice(),rollDice());
    return mRandomValue;
}

// Roll one dice
// Gibt einen Zufälligen Ins 1,..,6 zurück
int Control::rollDice(){
    return (rand() % 6) + 1;
}

// Return True, if a new game starts
bool Control::isNewGame() const{
    return mStartGame;
}
// Startet eine neue Spielrunde
void Control::setNewGame(){
    mStartGame = true;
}

//Return the last Value
Value Control::getLastValue() const{
    return mlastValue;
}
//Return the actual Value
Value Control::getNewValue() const{
    return(mNewValue);
}

Value Control::getOnlyRandomValue()const{
    return(mRandomValue);
}

// Set the Vallue which was called
/*
 * Überfüht einen Passenden Int in ein Value,
 * Der aktuelle Call-Wert ersetzt den letzten Call-Wert
 * und erhält selbst den Value-Wert
 *
 * Behandeln das Ereigenis das Mia ausgesprochen wurde fehlt noch
 */
void Control::setCallValue(int v){
    int lowval = v%10;
    int highval = v/10;

    mlastValue.set(mNewValue);
    mNewValue.set(lowval,highval);
    mStartGame = false;
}

// Überprüft ob die eingabe korrekt ist
bool Control::Call_is_correct(int v){
    int lowval = v%10;
    int highval = v/10;
    return mStartGame || mlastValue.less_than(lowval,highval);
}

//Gibt einen Spieler passend zur ID zurück
Player Control::GetPlayer(int i) const{
    if(i < mPlayers.size())
        return mPlayers[i];
    return mPlayers[0];
}

// Gibt die ID des aktuellen Spilers zurück
int Control::GetActivPlayerID() const{
    return mActivPlayerID;
}
// Gibt die ID des vorigen Spielers zurück
int Control::GetLastPlayerID(){
    int ret = mActivPlayerID-1;
    if(ret < 0)
        return mPlayers.size()-1;
    return ret;
}

// Weitersetzen der ID des anktuellen Spielers
void Control::NextPlayer(){
    mActivPlayerID = (mActivPlayerID+1)%mPlayers.size();
}

// Behandelt das Event, dass die Würfel vom nächsten aufgedeckt werden, also der Lüge bezichtigt
// Muss noch getestet werden!
QString Control::look_at_last_Player(){
    int apid = GetActivPlayerID();
    int fpid = GetLastPlayerID();
    int loose=1;
    QString s = "Player "+ QString::number(apid)+" say Player "+QString::number(fpid)+" lies.\n\t";

    if(mNewValue.equal(mRandomValue) || mRandomValue.greater_than(mNewValue)){
        if(mRandomValue.mia){
            loose=2;
        }else{
            loose=1;
        }
        s=s+"Wrong! You loose "+ QString::number(loose)+" life(s)!";
        mPlayers[mActivPlayerID].looLife(loose);
        mPlayers[GetLastPlayerID()].addWin();
    }else{
        if(mNewValue.mia){
            loose=2;
        }else{
            loose=1;
        }
        s=s+"Right! He loose "+ QString::number(loose)+" life(s)!\nYou win!";

        mPlayers[GetLastPlayerID()].looLife(loose);
        mPlayers[mActivPlayerID].addWin();
    }
    return(s);
}
