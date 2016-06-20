#include "control.h"

#include <iostream>

Control::Control()
{    
    std::srand(std::time(NULL));
}

Control::~Control()
{

}

// Roll two dice and return the value
int Control::getRandomDice(){
    int a = rollDice();
    int b = rollDice();
    int ret = std::min(a,b)+(10*std::max(a,b));

    Value v1(1,1);
    Value v2(1,2);
    Value v3(2,3);

    std::cout <<std::boolalpha <<v1.equal(v1)<<" "<<std::boolalpha <<v1.less(v1)<<" "<<std::boolalpha <<v1.great(v1)<<" - "
             <<std::boolalpha <<v1.equal(v2)<<" "<<std::boolalpha <<v1.less(v2)<<" "<<std::boolalpha <<v1.great(v2)<<" - "
            <<std::boolalpha <<v1.equal(v3)<<" "<<std::boolalpha <<v1.less(v3)<<" "<<std::boolalpha <<v1.great(v3)<<" | "
           <<std::boolalpha <<v2.equal(v1)<<" "<<std::boolalpha <<v2.less(v1)<<" "<<std::boolalpha <<v2.great(v1)<<" - "
          <<std::boolalpha <<v2.equal(v2)<<" "<<std::boolalpha <<v2.less(v2)<<" "<<std::boolalpha <<v2.great(v2)<<" - "
         <<std::boolalpha <<v2.equal(v3)<<" "<<std::boolalpha <<v2.less(v3)<<" "<<std::boolalpha <<v2.great(v3)<<" | "
        <<std::boolalpha <<v3.equal(v1)<<" "<<std::boolalpha <<v3.less(v1)<<" "<<std::boolalpha <<v3.great(v1)<<" - "
       <<std::boolalpha <<v3.equal(v2)<<" "<<std::boolalpha <<v3.less(v2)<<" "<<std::boolalpha <<v3.great(v2)<<" - "
      <<std::boolalpha <<v3.equal(v3)<<" "<<std::boolalpha <<v3.less(v3)<<" "<<std::boolalpha <<v3.great(v3)<<std::endl;

    return ret;
}

// Roll one dice
int Control::rollDice(){
    return (rand() % 6) + 1;
}
