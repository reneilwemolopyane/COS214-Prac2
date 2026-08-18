#include "Trip.h"

Trip::Trip() : routeStrategy(nullptr){}

Trip::~Trip(){
    if(routeStrategy != nullptr){
        delete routeStrategy;
    }
    routeStrategy = nullptr;
}

void Trip::setRouteStrategy(RouteStrategy* newStrategy){
    if(newStrategy != routeStrategy)
    {
        delete routeStrategy;
        routeStrategy = newStrategy;
    }
}

std::string Trip::plan(){
    return routeStrategy->getRoute();
}