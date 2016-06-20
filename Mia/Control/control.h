#ifndef CONTROL_H
#define CONTROL_H

#include <ctime>
#include <cstdlib>

#include "Model/value.h"

class Control
{
private:
    int rollDice();
    Value mlastValue;
    Value mRandomValue;
    Value mNewValue;
    bool mStartGame;
public:
    Control();
    ~Control();
    Value getRandomValue();
    bool isNewGame() const;
    Value getLastValue() const;
    bool setCallValue(int v);
};

#endif // CONTROL_H
