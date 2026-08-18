#ifndef DESERT_H
#define DESERT_H

#include "WorldBuilder.h"

class Desert : public WorldBuilder{
    public:
       ~Desert()override{}
       NPC* createNPC() override;
       Terrain* createTerrain() override;
       Obstacle* createObstacle() override;
};
#endif