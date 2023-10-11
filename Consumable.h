#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <iostream>
using namespace std;

#include "Item.h"
#include "Player.h"

class Consumable: public Item
{
private:
    
public:
    
    virtual void useItem(Player*)=0;
    Consumable();
    ~Consumable();
};

Consumable::Consumable(/* args */)
{
}

Consumable::~Consumable()
{
}





#endif