#ifndef CONTROL_H
#define CONTROL_H

#include <ctime>
#include <cstdlib>

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
