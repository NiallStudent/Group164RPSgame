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
    Armour(int initID, string initname, string initdescription, double initialRockDef, double initialPaperDef, double initialScissorDef):Item(initID,initname,initdescription)
    {
        rockDef = initialRockDef;
        paperDef = initialPaperDef;
        ScissorsDef = initialScissorDef;
    }

    double get_rockDef(){
        return rockDef;
    }

    void set_rockDef(double newDef){
        rockDef=newDef; 
    }

    double get_paperDef(){
        return paperDef;
    }

    void set_paperDef(double newDef){
        paperDef=newDef; 
    }

    double get_scissorsDef(){
        return ScissorsDef;
    }

    void set_scissorsDef(double newDef){
        ScissorsDef=newDef; 
    }


    ~Armour(){};
};

#endif