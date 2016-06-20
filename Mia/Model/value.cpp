#include "value.h"

#include <algorithm>

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
    return equal(v.a,v.b);
}

bool Value::equal(int a, int b){
    return this->a == a && this->b == b;
}

bool Value::great(Value v){
    if(mia || v.mia){
        return mia && !v.mia;
    }else if(pasch == v.pasch || mia){
        return(b > v.b || (b == v.b && a > v.a));
    }else{
        return pasch;
    }
}

bool Value::great(int a, int b){
    return great(Value(a,b));
}


bool Value::less(Value v){
    if(mia || v.mia){
        return !mia && v.mia;
    }else if(pasch == v.pasch || v.mia){
        return((!mia && v.mia) || b < v.b || (b == v.b && a < v.a));
    }else{
        return !pasch;
    }
}

bool Value::less(int a, int b){
    return great(Value(a,b));
}

int Value::toInt(){
    return a+(10*b);
}

QString Value::toQString(){
    return QString::number(this->toInt());
}
