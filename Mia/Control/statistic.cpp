#include "statistic.h"

#include <iostream>
#include "Model/value.h"

Statistic::Statistic()
{
    std::srand(std::time(NULL));
}

Statistic::~Statistic()
{

}

//Gibt einen Zufälligen Größeren Wert zurück als v
int Statistic::getRandomGratherValue(int v){
  for(int i = 0; i < 36; i++){
      if(mValue[i] == v){
          return mValue[1+i+(rand() %(35-i))];
      }
  }
}
