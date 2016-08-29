#include "value.h"

#include <algorithm>
Value::Value()
{
    Value(0,1);
}

Value::Value(int v){
    int a = v%10;
    int b = v/10;
    this->lowval = std::min(a,b);
    this->highval = std::max(a,b);
    pasch = a==b;
    mia = this->lowval == 1 && this->highval == 2;
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
void Value::set(int v){
    int lowval = v%10;
    int highval = v/10;
    set(lowval,highval);
}

//Prüft auf Gleichheit der Werte
bool Value::equal(Value v){
    return this->lowval == v.lowval && this->highval == v.highval;
}
bool Value::equal(int a, int b){
    return equal((Value(a,b)));
}
bool Value::equal(int v){
    int l = v%10;
    int h = v/10;
    return equal(std::min(l,h),std::max(l,h));
}

//Prüft ob dieser Werte größer ist als der gegebene
bool Value::greater_than(Value v){
    if(v.mia){
        return false;
    }else if(mia){
        return true;
    }else if(pasch == v.pasch){
        return(highval > v.highval || (highval == v.highval && lowval > v.lowval));
    }else{
        return pasch;
    }
}
bool Value::greater_than(int a, int b){
    return greater_than(Value(a,b));
}
bool Value::greater_than(int v){
    int l = v%10;
    int h = v/10;
    return greater_than(std::min(l,h),std::max(l,h));
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
bool Value::less_than(int v){
    int l = v%10;
    int h = v/10;
    return less_than(std::min(l,h),std::max(l,h));
}

// Parst den Value zu einem int
int Value::toInt(){
    return lowval+(10*highval);
}

// Parst den Value zu einem QString
QString Value::toQString(){
    return QString::number(this->toInt());
}

//Setzt es auf einen "Neutralen" kleinen Wert
void Value::clear(){
    set(0,1);
}
