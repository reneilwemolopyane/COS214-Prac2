#include "Forest.h"
#include "ForestObstacle.h"
#include "ForestNPC.h"
#include "ForestTerrain.h"

NPC* Forest::createNPC(){
    return new ForestNPC();
}
Terrain* Forest::createTerrain(){
    return new ForestTerrain();
}
Obstacle* Forest::createObstacle(){
    return new ForestObstacle();
}