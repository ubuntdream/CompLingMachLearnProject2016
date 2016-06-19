#include "control.h"

#include <iostream>

Control::Control()
{    
    std::srand(std::time(NULL));
}

Control::~Control()
{

}

// Roll two dice and return the value
int Control::getRandomDice(){
    int a = rollDice();
    int b = rollDice();
    int ret = std::min(a,b)+(10*std::max(a,b));
    return ret;
}

// Roll one dice
int Control::rollDice(){
    return (rand() % 6) + 1;
}
