#include "primitiveki.h"
#include <iostream>

PrimitiveKI::PrimitiveKI():KI()
{
    std::srand(std::time(NULL));
}


bool PrimitiveKI::look_at_dice(Value last, Value call, bool startGame){

    bool result =false;
//    std::cout<<"lastValue=" << last.toInt()<<". callvalue=" << call.toInt() <<std::endl;
    int index;
    float p = getProbabilityGreatherX(call,&index);

//    std::cout<< "HUGO--p "<<p<<std::endl;
    //If random is smaller or equal than show probability- we should look at dices
    if( (((float)rand())/(float)RAND_MAX) < 1-p){
        result =true;
//        std::cout<< "HUGO--call "<<call.toInt()<<std::endl;
    }

    return result;
}

float PrimitiveKI::getProbabilityGreatherX(Value x, int *indiceX){

    int val = x.toInt();
//    std::cout<< "XP="<<xprobabilities[1]<<std::endl;
    //21 is length of arrays
    float cumsum=0;
    bool searching = true;
    for(int i=0; i< 21 && searching;i++){
        cumsum += xprobabilities[i];
        if(xresults[i]==val){
            //finishes the loop without using ugly return
            searching =false;
            *indiceX=i;
        }
    }

    //Probability to be greather than x
    return 1-cumsum;
}

int PrimitiveKI::getCall(Value last, Value rand){
    int result = 0;
    if(rand.greater_than(last)){
        result = rand.toInt();
    }
    else{
        result = getRandomValueGreaterX(last);
    }
    return result;
}

int PrimitiveKI::getRandomValueGreaterX(Value x){
    int val = x.toInt();
    int index;
    getProbabilityGreatherX(x,&index);
//    std::cout<<index;
    //chose random index greather index of value
    int indrand=0;
    if(index <20){
        indrand = (rand()) %(20-index) + index+1;
    }

    return xresults[indrand];
}

int PrimitiveKI::getStartCall(Value v){
    return v.toInt();
}
