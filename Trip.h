#ifndef TRIP_H
#define TRIP_H

#include "RouteStrategy.h"
#include <string>

class Trip{
    private:
       RouteStrategy* routeStrategy;
    public: 
       Trip();
       ~Trip();

       void setRouteStrategy(RouteStrategy* newStrategy);
       std::string plan();

}
#endif