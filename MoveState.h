#ifndef MOVESTATE_H
#define MOVESTATE_H
class Traveller;

class MoveState{
    
    public:
       virtual void doMove(Traveller& traveller) = 0;
       virtual ~MoveState();
       virtual MoveState* getNextMove(Traveller& traveller) = 0;
};
#endif
