#include "MoveByBoat.h"
#include "MoveByFoot.h"
#include <iostream>
#include "Traveller.h"

void MoveByBicycle::doMove(Traveller& traveller){
    std::cout << "Cycling three steps along the road." <<std::endl;
    traveller.advance(3);
}

MoveState* MoveByBicycle::getNextMove(Traveller& traveller){
    if(traveller.isAtDock()){
        traveller.pack(this);
        return new MoveByBoat();
    }
    if(traveller.isAtBikeRack()){
        return new MoveByFoot();
    }
    return;
}