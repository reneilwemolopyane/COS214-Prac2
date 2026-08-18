#include "MoveByFoot.h"
#include "Traveller.h"
#include "MoveByCar.h"
#include "MoveByBicycle.h"
#include <iostream>

void MoveByFoot::doMove(Traveller& traveller){
    std::cout << "Moving one step forward" <<std::endl;
    traveller.advance(1);
}
MoveState* MoveByFoot::getNextMove(Traveller& traveller){
    if(traveller.isAtBikeRack()){
        return new MoveByBicycle();
    }
    if(traveller.isAtGarage()){
        return new MoveByCar();
    }
    if(traveller.isAtShore()){
        return new MoveByBoat();
    }
    return this;
}