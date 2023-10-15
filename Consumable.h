#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <iostream>
using namespace std;
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

class Consumable: public Item
{
private:
    
public:
    
     virtual void useItem(Actor* a){
        cout<<"called consumable player useItem()";
     }; 

    Consumable(){};
    ~Consumable(){};
};







#endif