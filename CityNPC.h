#ifndef CITYNPC_H
#define CITYNPC_H

#include "NPC.h"

class CityNPC : public NPC{
    public:
       void print()override;
       ~CityNPC()override;
};

#endif
