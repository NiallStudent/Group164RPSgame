#ifndef ARMOUR_H
#define ARMOUR_H

#include <iostream>
using namespace std;
#include "Item.h"

class Armour:public Item
{
private:
    double rockDef, paperDef, ScissorsDef;

public:
    Armour(/* args */) : Armour(200,"defaultArmour","defaultArmourDescription",2,2,2){};
    Armour(int id, string name, string description, double rockDef, double paperDef, double scissorDef):Item(id,name,description)
    {
        this->rockDef = rockDef;
        this->paperDef = paperDef;
        this->ScissorsDef = scissorDef;
    }

    double get_rockDef(){
        return this->rockDef;
    }

    void set_rockDef(double newDef){
        this->rockDef=newDef; 
    }

    double get_paperDef(){
        return this->paperDef;
    }

    void set_paperDef(double newDef){
        this->paperDef=newDef; 
    }

    double get_scissorsDef(){
        return this->ScissorsDef;
    }

    void set_scissorsDef(double newDef){
        this->ScissorsDef=newDef; 
    }


    ~Armour(){};
};

#endif