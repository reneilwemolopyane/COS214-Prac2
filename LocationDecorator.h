#ifndef LOCATIONDECORATOR
#define LOCATIONDECORATOR


#include <string>
#include <iostream>
#include <vector>
#include "Map.h"


using namespace std;

//class Map;

class LocationDecorator : public Map{

protected:

Map* map;

public:

//Function 1:
LocationDecorator(Map* map);

//Function 2:
virtual void print() = 0;

//Function 3:
virtual ~LocationDecorator();


};

class WeatherLocation : public LocationDecorator{

private:

string weather;

public:

//Function 4:
WeatherLocation(Map* map, string weather);

//Function 5:
void print();


};


class TollLocation : public LocationDecorator{

private:

string toll;

public:

//Function 6:
TollLocation(Map* map, string toll);

//Function 7:
void print();


};


class QuestLocation : public LocationDecorator{

private:

string quest;

public:

//Function 8:
QuestLocation(Map* map, string quest);

//Function 9:
void print();


};





#endif