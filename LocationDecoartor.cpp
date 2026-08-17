#include <string>
#include <iostream>
#include <vector>
#include "LocationDecorator.h"


using namespace std;

//Function 1:
LocationDecorator::LocationDecorator(Map* map){


this->map = map;

}

//Function 3:
LocationDecorator::~LocationDecorator(){

delete map;

}


//Function 4:
WeatherLocation::WeatherLocation(Map* map ,string weather): LocationDecorator(map){

this->weather = weather;

}

//Function 5:
void WeatherLocation::print(){

map->print();

cout << "Weather : " << weather << endl;

}

//Function 6:
TollLocation::TollLocation(Map* map, string toll): LocationDecorator(map){

this->toll = toll;

}

//Function 7:
void TollLocation::print(){

map->print();

cout<< "Toll : " << toll <<endl;

}


//Function 8:
QuestLocation::QuestLocation(Map* map, string quest): LocationDecorator(map){

this->quest = quest;

}

//Function 9:
void QuestLocation::print(){

map->print();

cout << "Quest : " << quest <<endl;


}
