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

// Setzt lowval und highval girekt auf den Wert
void Value::set(Value v){
    set(v.lowval,v.highval);
}
void Value::set(int plowVal, int phighval){
    this->lowval = std::min(plowVal,phighval);
    this->highval = std::max(plowVal,phighval);
    pasch = plowVal==phighval;
    mia = this->lowval == 1 && this->highval == 2;
}

//Prüft auf Gleichheit der Werte
bool Value::equal(Value v){
    return this->lowval == v.lowval && this->highval == v.highval;
}
bool Value::equal(int a, int b){
    return equal((Value(a,b)));
}

//Prüft ob dieser Werte größer ist als der gegebene
bool Value::greater_than(Value v){
    if(mia)
        return !v.mia;
    else if(pasch == v.pasch){
        return(highval > v.highval || (highval == v.highval && lowval > v.lowval));
    }else{
        return pasch;
    }
}
bool Value::greater_than(int a, int b){
    return greater_than(Value(a,b));
}

//Prüft ob dieser Werte keiner ist als der gegebene
bool Value::less_than(Value v){
    if(mia){
        return false;
    }else if(v.mia){
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

// Parst den Value zu einem int
int Value::toInt(){
    return lowval+(10*highval);
}

// Parst den Value zu einem QString
QString Value::toQString(){
    return QString::number(this->toInt());
}
