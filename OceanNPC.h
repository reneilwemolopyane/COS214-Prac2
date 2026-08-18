#ifndef OCEANNPC_H
#define OCEANNPC_H

#include "NPC.h"

class OceanNPC : public NPC{
    public:
       void print()override;
       ~OceanNPC()override;
};

#endif
