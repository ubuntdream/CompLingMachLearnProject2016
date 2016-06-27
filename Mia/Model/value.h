#ifndef VALUE_H
#define VALUE_H

#include <QString>

class Value
{
public:
    Value(int lowval, int highval);
    Value();
    ~Value();

    int lowval,highval;
    bool pasch,mia;

    void set(int lowval, int highval);
    void set(Value v);

    bool equal(int lowval, int highval);
    bool equal(Value v);

    bool greater_than(int lowval, int highval);
    bool greater_than(Value v);

    bool less_than(int lowval, int highval);
    bool less_than(Value v);

    int toInt();
    QString toQString();

};

#endif // VALUE_H
