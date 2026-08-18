#ifndef FORESTNPC_H
#define FORESTNPC_H

#include "NPC.h"

class ForestNPC : public NPC{
    public:
       void print()override;
       ~ForestNPC()override;
};

#endif
