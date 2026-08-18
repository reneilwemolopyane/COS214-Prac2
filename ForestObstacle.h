#ifndef FORESTOBSTACLE_H
#define FORESTOBSTACLE_H

#include "Obstacle.h"

class ForestObstacle : public Obstacle{
    public:
       void print()override;
       ~ForestObstacle()override;
};

#endif
