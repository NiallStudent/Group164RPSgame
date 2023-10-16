#ifndef POTION_H
#define POTION_H

#include <iostream>
using namespace std;
#include "Consumable.h"
//Forward declare player to avoid circular calls.
class Player;

class Potion : public Consumable
{
private:
    int healAmount = 50;

public:
    Potion()
    {
        description = "Heals 50hp. Can heal past starting hp";
        name = "Healing Potion";
        this->ID = 302;
    };
    ~Potion(){};

    // THis is giving errors, player has not been declared
    virtual void useItem(Actor *p) override
    {
        int currentPlayerHP = p->get_HP();
        p->set_HP(currentPlayerHP + healAmount);
        cout << "Healed 50 hp" << endl;
    };

};
#endif

