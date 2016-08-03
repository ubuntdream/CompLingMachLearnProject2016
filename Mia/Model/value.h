#ifndef VALUE_H
#define VALUE_H

#include <QString>

class Value
{
public:
    Value(int lowval, int highval);
    Value(int v);
    Value();
    ~Value();

    // lowval ist der kleinere Wert der Würfel
    // highval ist der größere Wert der Würfel
    int lowval,highval;
    // gibt an, ob es sich um einen Pasch oder Mexxchen handelt
    bool pasch,mia;

    void set(int lowval, int highval);
    void set(Value v);
    void set(int v);

    bool equal(int lowval, int highval);
    bool equal(Value v);
    bool equal(int v);


    bool greater_than(int lowval, int highval);
    bool greater_than(Value v);
    bool greater_than(int v);

    bool less_than(int lowval, int highval);
    bool less_than(Value v);
    bool less_than(int v);

    int toInt();
    QString toQString();

    void clear();
};

#endif // VALUE_H
