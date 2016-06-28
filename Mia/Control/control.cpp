#include "control.h"

#include <iostream>

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
int Control::rollDice(){
    return (rand() % 6) + 1;
}

// Return True, if a new game starts
bool Control::isNewGame() const{
    return mStartGame;
}

//Return the last Value
Value Control::getLastValue() const{
    return mlastValue;
}

// Set the Vallue which was called
void Control::setCallValue(int v){
    int lowval = v%10;
    int highval = v/10;

    mlastValue.set(mNewValue);
    mNewValue.set(lowval,highval);
    mStartGame = false;
}

bool Control::Call_is_correct(int v){
    int lowval = v%10;
    int highval = v/10;
     // wozu soll der hintere teil gut sein? ich muss doch immer größer als der letzte wert sein.
    return mStartGame || mlastValue.less_than(lowval,highval); //|| (mlastValue.mia && mlastValue.equal(lowval,highval));
}

Player Control::GetPlayer(int i) const{
    if(i < mPlayers.size())
        return mPlayers[i];
    return mPlayers[0];
}

int Control::GetActivPlayerID() const{
    return mActivPlayerID;
}
void Control::NextPlayer(){
    mActivPlayerID = (mActivPlayerID+1)%mPlayers.size();
}
