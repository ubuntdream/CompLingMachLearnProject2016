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

// Set the Vallue witch called
bool Control::setCallValue(int v){
    int a = v%10;
    int b = v/10;

    if(mStartGame || mlastValue.less_tan(a,b) || (mlastValue.mia && mlastValue.equal(a,b))){
        mNewValue.set(a,b);
        mStartGame = false;
        return true;
    }
    return false;
}
