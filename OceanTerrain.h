#ifndef OCEANTERRAIN_H
#define OCEANTERRAIN_H

#include "Terrain.h"

class OceanTerrain : public Terrain{
    public:
       void print()override;
       ~OceanTerrain()override;
};

#endif
