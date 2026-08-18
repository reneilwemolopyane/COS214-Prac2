#include "Traveller.h"
#include "MoveByFoot.h"
#include <iostream>

Traveller::Traveller(){
    current = new MoveByFoot();
    parkedState = nullptr;
    position = 0;
    atBikeRack = false;
    atDock = false;
    atGarage = false;
}

bool Traveller::isAtDock()const{
    return atDock;
}

bool isAtGarage()const{
    return atGarage;
}

bool isAtBikeRack()const{
    return atBikeRack;
}

Traveller::~Traveller(){
    if(current!=nullptr){
        delete current;
    }
    current = nullptr;
    if(parkedState!=nullptr){
        delete parkedState;
    }
    parkedState = nullptr;
}

void Traveller::enterBikeRack(){
    atBikeRack = true;
}

void Traveller::enterDock(){
    atDock = true;
}

void Traveller::enterGarage(){
    atGarage = true;
}

void Traveller::move(){
    current->doMove(*this);
    MoveState* next = current->getNextMove(*this);
    setState(next);
}

void Traveller::setState(MoveState* newState){
    if(newState != current){
        if(current != parkedState){
            current = newState;
        }
    }
    
}

void Traveller::advance(int steps){
    position += steps;
}

int Traveller::getPosition()const{
    return position;
}

void Traveller::park(MoveState* vehicle){
    if(parkedState != nullptr && parkedState != vehicle){
        delete parkedState;
    }
    parkedState = vehicle;
}

MoveState* Traveller::takeParked(){
    MoveState* recovered = parkState;
    parkState = nullptr;
    return recovered;
}

