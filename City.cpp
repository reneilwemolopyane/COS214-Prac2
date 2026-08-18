#include "City.h"
#include "CityObstacle.h"
#include "CityNPC.h"
#include "CityTerrain.h"

NPC* City::createNPC(){
    return new CityNPC();
}
Terrain* City::createTerrain(){
    return new CityTerrain();
}
Obstacle* City::createObstacle(){
    return new CityObstacle();
}