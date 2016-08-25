#ifndef PRIMITIVEKI_H
#define PRIMITIVEKI_H
#include <ctime>
#include <cstdlib>
#include "Model/value.h"

/****************************************************
 * Background to this ingame artificial intelligence:
 * Checks cumulative probabilities CP of all possible
 * dice values greather than the actual call value.
 * Then decides to look at the dice with P=1-CP.
 *
 * This leads to: We will look at dice values to a
 * certain probability depending on how many possible
 * values greather than the call exist
*****************************************************/
class PrimitiveKI
{
private:
    float getProbabilityGreatherX(Value x, int * indiceX);
    int getRandomValueGreaterX(Value x);

protected:
    //results of Random Variable X in ascending order of priority
    int xresults[21] = {31,32,41,42,43,51,52,
                      53,54,61,62,63,64,65,
                      11,22,33,44,55,66,21};
    int xprobabilities[21] ={2/36,2/36,2/36,2/36,2/36,2/36,2/36,
                           2/36,2/36,2/36,2/36,2/36,2/36,2/36,
                           1/36,1/36,1/36,1/36,1/36,1/36,2/36};
public:
    PrimitiveKI();

    //Sollten dazu vllt ein Interface machen...
    bool look_at_dice(Value last, Value call);
    int getCall(Value last, Value rand);
};

#endif // PRIMITIVEKI_H
