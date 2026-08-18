#ifndef FOREST_H
#define FOREST_H

#include "WorldBuilder.h"

class Forest : public WorldBuilder{
    public:
        ~Forest()override{}
       NPC* createNPC() override;
       Terrain* createTerrain() override;
       Obstacle* createObstacle() override;
};
#endif