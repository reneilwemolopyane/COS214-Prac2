#ifndef WORLDBUILDER_H
#define WORLDBUILDER_H

#include "NPC.h"
#include "Terrain.h"
#include "Obstacle.h"

class WorldBuilder{
    public:
      virtual ~WorldBuilder(){};
      virtual NPC* createNPC()=0;
      virtual Terrain* createTerrain()=0;
      virtual Obstacle* createObstacle()=0;
};
#endif
