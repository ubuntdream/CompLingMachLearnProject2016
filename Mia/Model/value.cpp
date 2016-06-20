#include "value.h"

#include <algorithm>
Value::Value()
{
    Value(0,0);
}


Value::Value(int a, int b)
{
    this->a = std::min(a,b);
    this->b = std::max(a,b);
    pasch = a==b;
    mia = this->a == 1 && this->b == 2;
}

Value::~Value()
{

}

void Value::set(Value v){
    set(v.a,v.b);
}

void Value::set(int a, int b){
    this->a = std::min(a,b);
    this->b = std::max(a,b);
    pasch = a==b;
    mia = this->a == 1 && this->b == 2;
}

bool Value::equal(Value v){
    return this->a == v.a && this->b == v.b;
}

bool Value::equal(int a, int b){
    return equal((Value(a,b)));
}

bool Value::great_tan(Value v){
    if(mia)
        return false;
    else if(pasch == v.pasch){
        return(b > v.b || (b == v.b && a > v.a));
    }else{
        return pasch;
    }
}

bool Value::great_tan(int a, int b){
    return great_tan(Value(a,b));
}


bool Value::less_tan(Value v){
    if(v.mia){
        return true;
    }else if(pasch == v.pasch){
        return(b < v.b || (b == v.b && a < v.a));
    }else{
        return !pasch;
    }
}

bool Value::less_tan(int a, int b){
    return less_tan(Value(a,b));
}

int Value::toInt(){
    return a+(10*b);
}

QString Value::toQString(){
    return QString::number(this->toInt());
}
