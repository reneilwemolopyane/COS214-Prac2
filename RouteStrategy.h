#ifndef ROUTESTRATEGY_H
#define ROUTESTRATEGY_H

#include <string>
class RouteStrategy{
    public: 
       virtual ~RouteStrategy();
       virtual std::string getRoute() = 0;
};

#endif