#ifndef DESERTOBSTACLE_H
#define DESERTOBSTACLE_H

#include "Obstacle.h"

class DesertObstacle : public Obstacle{
    public:
       void print()override;
       ~DesertObstacle()override;
};

#endif
