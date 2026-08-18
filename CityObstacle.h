#ifndef CITYOBSTACLE_H
#define CITYOBSTACLE_H

#include "Obstacle.h"

class CityObstacle : public Obstacle{
    public:
       void print()override;
       ~CityObstacle()override;
};

#endif
