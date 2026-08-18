#include "Ocean.h"
#include "OceanObstacle.h"
#include "OceanNPC.h"
#include "OceanTerrain.h"

NPC* Ocean::createNPC(){
    return new OceanNPC();
}
Terrain* Ocean::createTerrain(){
    return new OceanTerrain();
}
Obstacle* Ocean::createObstacle(){
    return new OceanObstacle();
}