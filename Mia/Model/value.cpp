#include "value.h"

#include <algorithm>
Value::Value()
{
    Value(0,0);
}


Value::Value(int a, int b)
{
    this->lowval = std::min(a,b);
    this->highval = std::max(a,b);
    pasch = a==b;
    mia = this->lowval == 1 && this->highval == 2;
}

Value::~Value()
{

}

void Value::set(Value v){
    set(v.lowval,v.highval);
}

void Value::set(int plowVal, int phighval){
    this->lowval = std::min(plowVal,phighval);
    this->highval = std::max(plowVal,phighval);
    pasch = plowVal==phighval;
    mia = this->lowval == 1 && this->highval == 2;
}

bool Value::equal(Value v){
    return this->lowval == v.lowval && this->highval == v.highval;
}

bool Value::equal(int a, int b){
    return equal((Value(a,b)));
}

bool Value::greater_than(Value v){
    if(mia)
        return false;
    else if(pasch == v.pasch){
        return(highval > v.highval || (highval == v.highval && lowval > v.lowval));
    }else{
        return pasch;
    }
}

bool Value::greater_than(int a, int b){
    return greater_than(Value(a,b));
}


bool Value::less_than(Value v){
    if(mia){return false;}//dann ist das spiel vorbei oder nicht?
    if(v.mia){
        return true;
    }else if(pasch == v.pasch){
        return(highval < v.highval || (highval == v.highval && lowval < v.lowval));
    }else{
        return !pasch;
    }
}

bool Value::less_than(int a, int b){
    return less_than(Value(a,b));
}

int Value::toInt(){
    return lowval+(10*highval);
}

QString Value::toQString(){
    return QString::number(this->toInt());
}
