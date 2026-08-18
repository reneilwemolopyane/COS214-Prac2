#ifndef OCEAN_H
#define OCEAN_H

#include "WorldBuilder.h"

class Ocean : public WorldBuilder{
    public:
        ~Ocean()override{}
       NPC* createNPC() override;
       Terrain* createTerrain() override;
       Obstacle* createObstacle() override;
};
#endif