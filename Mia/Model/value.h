#ifndef VALUE_H
#define VALUE_H

#include <QString>

class Value
{
public:
    Value(int a, int b);
    ~Value();

    int a,b;
    bool pasch,mia;

    void set(int a, int b);
    void set(Value v);

    bool equal(int a, int b);
    bool equal(Value v);

    bool great(int a, int b);
    bool great(Value v);

    bool less(int a, int b);
    bool less(Value v);

    int toInt();
    QString toQString();

};

#endif // VALUE_H
