#ifndef CITYTERRAIN_H
#define CITYTERRAIN_H

#include "Terrain.h"

class CityTerrain : public Terrain{
    public:
       void print()override;
       ~CityTerrain()override;
};

#endif
