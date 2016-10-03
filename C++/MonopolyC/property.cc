#include <iostream>
#include <vector>
#include <string>
#include "property.h"
using namespace std;

Property::Property(){
    int rent = 0;
    int house = 0;
    string name = "Kevin's house";
    owner = 0;
}

Property::~Property(){
    int rent = 0;
    int house = 0;
    string name = "Kevin's house";
    owner = 0;
}

string Property::getName(){
    return name;
}

int Property::getID(){
    return id;
}

int Property::getRent(){
    if(monopoly)
    {
        if(house>0)
        {
            if(house==1)
            {
                return rent*4;
            }
            if(house==2)
            {
                return rent*12;
            }
            if(house==3)
            {
                return rent*28;
            }
            if(house==4)
            {
                return rent*34;
            }
        }
        else return rent*2;
    }
    return rent;
}

int Property::getHouse(){
    return house;
}

int Property::getOwner(){
    return owner;
}

int Property::getPrice(){
    return price;
}

bool Property::getMonopoly(){
    return monopoly;
}

void Property::editOwner(int Owner){
    owner = Owner;
}

void Property::editHouse(int House){
    house = House;
}

void Property::setMonopoly(bool Mono){
    monopoly = Mono;
}


void Property::init(int ID, int Price, int Rent, string Name){
    name = Name;
    id = ID;
    price = Price;
    rent = Rent;
}

