#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "Player.h"

class potion:public Item
{
private:
    int healAmt;
    
public:
    potion():Item(301,"potion","Heal 20 HP"){
        this->healAmt=20;
    };


    ~potion(){};

    void heal(Player* p){
        p->set_health(20);
    }


};

#endif


