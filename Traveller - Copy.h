#ifndef TRAVELLER_H
#define TRAVELLER_H

#include "MoveState.h"
class Traveller{
    private:
       MoveState* current;
       MoveState* parkedState;
       int position;
       bool atBikeRack;
       bool atDock;
       bool atGarage;
       
    public:
       Traveller();
       ~Traveller();

       void move();
       void setState(MoveState* newState);
       void advance(int steps);
       int getPosition()const;
       void park(MoveState* vehicle);
       MoveState* takeParked();

       bool isAtDock()const;
       bool isAtGarage()const;
       bool isAtBikeRack()const;

       void enterBikeRack();
       void enterDock();
       void enterGarage();

};
#endif