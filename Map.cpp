#include <string>
#include <iostream>
#include <vector>
#include "Map.h"

using namespace std;

//Function 6:
void Location::print(){

cout << "Location : " << name << ", " << country  <<endl;

}


//Function 7:
void Region::print(){
    
    for(Map* child : children){

        child->print();
    }


}

//Function 8:
void Region::add(Map* map){

children.push_back(map);

}

//Function 9:
void Region::remove(Map* map){

for(auto it = children.begin(); it != children.end()){

    if(*it == map){

        children.erase(it);

        return;
    }

}

}

//Function 10:
Map* Region::getChild(int index){

return children[index];

}

//Function 11:
Region::~Region(){

for (Map* child : children){

    delete child;
}

}
