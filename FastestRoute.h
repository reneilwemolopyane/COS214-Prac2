#ifndef FASTESTROUTE_H
#define FASTESTROUTE_H

#include "RouteStrategy.h"

class FastestRoute : public RouteStrategy{
    public:
       ~FastestRoute()override;
       std::string getRoute()override;
       
};
#endif