#ifndef MOVEBYFOOT_H
#define MOVEBYFOOT_H

#include "MoveState.h"

class MoveByFoot : public MoveState{
    public:
       MoveByFoot();
       void doMove(Traveller& traveller) override;
       MoveState* getNextMove(Traveller& traveller) override;
       ~MoveByFoot() override;
       
};
#endif

