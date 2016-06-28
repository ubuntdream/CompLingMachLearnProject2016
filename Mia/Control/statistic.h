#ifndef STATISTIC_H
#define STATISTIC_H

#include <ctime>
#include <cstdlib>

//Dise Klasse beinhaltet Statistiken bei theoretischen Verteilung
class Statistic
{
protected:
    //Speicherung der verschiedenen Elemente in richtiger Reihenfolge
    int mValue[36] = {31,31,32,32,
                      41,41,42,42,43,43,
                      51,51,52,52,53,53,54,54,
                      61,61,62,62,63,63,64,64,65,65,
                      11,22,33,44,55,66,21,21};
    int getRandomGratherValue(int v);
public:
    Statistic();
    ~Statistic();
};

#endif // STATISTIC_H
