#ifndef SCENICROUTE_H
#define SCENICROUTE_H

#include "RouteStrategy.h"

class ScenicRoute : public RouteStrategy{
    public:
       ~ScenicRoute()override;
       std::string getRoute()override;
       
};
#endif