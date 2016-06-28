#include "statistic.h"

#include <iostream>

Statistic::Statistic()
{
    std::srand(std::time(NULL));

    for(int i = 0; i < 36; i++){
        std::cout<<mValue[i]<<" ";
    }
    std::cout<<std::endl;

    for(int i = 0; i < 36; i++){
        std::cout<<getRandomGratherValue(31)<<" ";
    }
    std::cout<<std::endl;
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
