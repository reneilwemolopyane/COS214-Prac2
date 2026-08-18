#ifndef FORESTTERRAIN_H
#define FORESTTERRAIN_H

#include "Terrain.h"

class ForestTerrain : public Terrain{
    public:
       void print()override;
       ~ForestTerrain()override;
};

#endif
