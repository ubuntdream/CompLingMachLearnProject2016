#include "statistic.h"

Statistic::Statistic() : KI()
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
  return mValue[rand() %36];
}

// Berechnet die Wahrscheinlichkeit zurück, dass ein größerer Wert gewürfelt wird
int Statistic::getProbertyRollGrather(int v){
    for(int i = 0; i < 36; i++){
        if(mValue[i]== v){
            if(i < 28 || i >=34){
                return 34-i;
            }else{
                return 35-i;
            }
        }
    }
    return 36;
}

// Entscheidet, ob die Würfel aufgedekt werden sollen
/*
 * Ist die Wahrscheinlichkeit der Lüge höher, dann decke auf,
 * Entsheidung anhand der Wahrscehinlichkeit einen größeren Wert als
 * der Letzte Wert zu werfen
*/
bool Statistic::look_at_dice(Value last, Value call){
    return 18>getProbertyRollGrather(call.toInt());
}

// Gibt den passenden nächsten Call-Wert
/* Ist der zufällig gewürfelte Wert passend, gebe diesen zurück
 * ist nicht passend, wird zufällig ein größerer bestimmt
 */
 int Statistic::getCall(Value last, Value rand){
     if(rand.greater_than(last)){
         return rand.toInt();
     }else{
         return getRandomGratherValue(last.toInt());
     }
 }

// Gibt den Wert beim ersten Spiel aus
/*
 * Es wird immer die Wahrheit gesagt
 */
int Statistic::getStartCall(Value v){
    return v.toInt();
}
