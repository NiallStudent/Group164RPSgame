#ifndef BOMB_H
#define BOMB_H

#include <iostream>
using namespace std;


#include "Consumable.h"

class Player;
class Enemy;

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

    // THis is giving errors, player has not been declared
    void useItem(Enemy *e)
    {
        int currentPlayerHP = ;
        p->set_HP(currentPlayerHP + damageAmount);
        cout << "Healed 50 hp" << endl;
    };

};
#endif

