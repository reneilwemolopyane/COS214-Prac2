#include "MoveByFoot.h"
#include "Traveller.h"
#include "MoveByCar.h"
#include "MoveByBicycle.h"
#include <iostream>

void MoveByBoat::doMove(Traveller& traveller){
    std::cout << "Travelling by boat" << std::endl;
    traveller.advance(2);
}

MoveState* MoveByBoat::getNextMove(Traveller& traveller){
    if(traveller.isAtDock()){
        MoveState* recovered = traveller.takeParked();
        if(recovered != nullptr){
            return recovered;
        }
        return new MoveByFoot();
    }
    return this;
}