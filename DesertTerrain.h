#ifndef DESERTTERRAIN_H
#define DESERTTERRAIN_H

#include "Terrain.h"

class DesertTerrain : public Terrain{
    public:
       void print()override;
       ~DesertTerrain()override;
};

#endif
