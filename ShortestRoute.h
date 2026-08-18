#ifndef SHORTESTROUTE_H
#define SHORTESTROUTE_H

#include "RouteStrategy.h"

class ShortestRoute : public RouteStrategy{
    public:
       ~ShortestRoute()override;
       std::string getRoute()override;
       
};
#endif