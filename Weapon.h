#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
using namespace std;
#include "Item.h"


class weapon:public Item
{
private:

double rockAtkMultiplier, paperAtkMultiplier,scissorsAtkMultiplier;
    
public:
    weapon(/* args */):weapon(100,"DefaultWeapon","DefaultWeaponDescription",2,2,2){};
    weapon(int id, string name,string description, double rockAtk, double paperAtk, double scissorsAtk):Item(id,name,description){
        
        this->rockAtkMultiplier=rockAtk;
        this->paperAtkMultiplier=paperAtk;
        this->scissorsAtkMultiplier=scissorsAtk;
    };
    ~weapon(){};

    

    

    double get_rockAtk(){
        return this->rockAtkMultiplier;
    }

    double get_paperAtk(){
        return this->paperAtkMultiplier;
    }

    double get_scissorsAtk(){
        return this->scissorsAtkMultiplier;
    }
};

#endif
