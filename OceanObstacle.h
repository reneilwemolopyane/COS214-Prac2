#ifndef OCEANOBSTACLE_H
#define OCEANOBSTACLE_H

#include "Obstacle.h"

class OceanObstacle : public Obstacle{
    public:
       void print()override;
       ~OceanObstacle()override;
};

#endif
