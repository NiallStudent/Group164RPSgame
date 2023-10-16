#ifndef BOMB_H
#define BOMB_H

#include <iostream>
using namespace std;

//forward declare enemy to avoid circular declaraiton.
class Enemy;

#include "Consumable.h"



class Bomb : public Consumable
{
private:
    int damageAmount = 50;

public:
    Bomb()
    {
        description = "Deals 50 damage, regardless of enemy defence";
        name = "Bomb";
        this->ID = 303;
    };
    ~Bomb(){};

    
    virtual void useItem(Actor *e) override
    {
        int enemyHP=e->get_HP();
        e->set_HP(enemyHP-damageAmount);
        cout<<"KAMBOOM"<<endl;
    };

};
#endif

