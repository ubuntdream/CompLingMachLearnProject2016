#ifndef KI_H
#define KI_H

#include "Model/value.h"

// Oberklasse aller KIs, von dieser Klasse erben alle anderen KIs und gibt den grobe Rahem vor
class KI
{
public:
    KI();
    ~KI();
    virtual bool look_at_dice(Value last, Value call,bool startGame);
    virtual int getCall(Value last, Value rand);
    virtual int getStartCall(Value v);
    virtual void learn(Value call, Value rand, Value last, bool startGame);
    virtual void save();
};

#endif // KI_H
