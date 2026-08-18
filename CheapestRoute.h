#ifndef CHEAPEST_ROUTE_H
#define CHEAPEST_ROUTE_H

#include "RouteStrategy.h"

class CheapestRoute : public RouteStrategy{
    public:
       ~CheapestRoute()override;
       std::string getRoute()override;
       
};
#endif