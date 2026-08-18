#ifndef MOVEBYBOAT_H
#define MOVEBYBOAT_H

#include "MoveState.h"

class MoveByBoat : public MoveState{
    public:
       MoveByBoat();
       void doMove(Traveller& traveller) override;
       MoveState* getNextMove(Traveller& traveller) override;
       ~MoveByBoat() override;
       
};
#endif

