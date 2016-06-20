#ifndef CONTROL_H
#define CONTROL_H

#include <ctime>
#include <cstdlib>

#include "Model/value.h"

class Control
{
private:
    int rollDice();
public:
    Control();
    ~Control();
    int getRandomDice();
};

#endif // CONTROL_H
