#include "control.h"

#include <iostream>

Control::Control()
{    
    std::srand(std::time(NULL));
    mStartGame = true;
    mNewValue = Value();
    mRandomValue = Value();
    mlastValue = Value();
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

// Set the Vallue whitch was called
bool Control::setCallValue(int v){
    int lowval = v%10;
    int highval = v/10;

    if(mStartGame || mlastValue.less_than(lowval,highval) || (mlastValue.mia && mlastValue.equal(lowval,highval))){
        mlastValue.set(mNewValue);
        mNewValue.set(lowval,highval);
        mStartGame = false;
        return true;
    }
    return false;
}
