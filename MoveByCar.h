#ifndef MOVEBYCAR_H
#define MOVEBYCAR_H

#include "MoveState.h"

class MoveByCar : public MoveState{
    public:
       MoveByCar();
       void doMove(Traveller& traveller) override;
       MoveState* getNextMove(Traveller& traveller) override;
       ~MoveByCar() override;
       
};
#endif

