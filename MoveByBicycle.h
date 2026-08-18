#ifndef MOVEBYBICYCLE_H
#define MOVEBYBICYCLE_H

#include "MoveState.h"

class MoveByBicycle : public MoveState{
    public:
       MoveByBicycle();
       void doMove(Traveller& traveller) override;
       MoveState* getNextMove(Traveller& traveller) override;
       ~MoveByBicycle() override;
       
};  
#endif

