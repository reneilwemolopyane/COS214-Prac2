#ifndef CITY_H
#define CITY_H

#include "WorldBuilder.h"

class City : public WorldBuilder{
    public:
        ~City()override{}
       NPC* createNPC() override;
       Terrain* createTerrain() override;
       Obstacle* createObstacle() override;
};
#endif