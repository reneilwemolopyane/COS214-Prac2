#include "MoveByFoot.h"
#include "Traveller.h"
#include "MoveByBicycle.h"
#include "MoveByCar.h"
#include <iostream>

void MoveByCar::doMove(Traveller& traveller){
    std::cout << "Travelling by car" <<std::endl;
    traveller.advance(5);
}

MoveState* MoveByCar::getNextMove(Traveller& traveller){
    if(traveller.isAtGarage()){
        return new MoveByFoot();
    }
    if(traveller.isAtDock()){
        traveller.park(this);
        return new MoveByBoat();
    }
    return this;
}