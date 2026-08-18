#include "Desert.h"
#include "DesertObstacle.h"
#include "DesertNPC.h"
#include "DesertTerrain.h"

NPC* Desert::createNPC(){
    return new DesertNPC();
}
Terrain* Desert::createTerrain(){
    return new DesertTerrain();
}
Obstacle* Desert::createObstacle(){
    return new DesertObstacle();
}