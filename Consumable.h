#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <iostream>
using namespace std;
#include "Player.h"
#include "Item.h"

class Consumable: public Item
{
private:
    
public:
    
     virtual void useItem(Player* p){
        cout<<"used default consumable"<<endl;
    }; 
    Consumable(){};
    ~Consumable(){};
};







#endif