#ifndef MAP
#define MAP


#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Map{

public:

//Function 1:
virtual void print() = 0;

//Function 2:
virtual void add(Map* map) = 0;

//Function 3:
virtual void remove(Map* map) = 0;

//Function 4:
virtual Map* getChild(int index) = 0;

//Function 5:
virtual ~Map();


};

class Location : public Map{

private:
string name;

string country;

//Function 6:
void print();


};

class Region : public Map{

private:
vector<Map*> children;

public:

//Function 7:
void print();

//Function 8:
void add(Map* map);

//Function 9:
void remove(Map* map);

//Function 10:
Map* getChild(int index);

//Function 11:
~Region();

};


#endif