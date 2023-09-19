#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include "Weapon.h"
#include "Armour.h"

class Player
{
private:
    string name;
    int HP;
    double Attack, rockAttack, paperAttack, scissorsAttack;
    double Defence, rockDefence, paperDefence, scissorsDefence;
    int gold;
    weapon currentweapon;
    Armour currentarmour;

public:
    Player() : Player("defaultName", 100, 20, 20){};
    Player(string name, int HP, double Attack, double Defence)
    {
        this->name = name;
        this->Attack = Attack;
        this->rockAttack = Attack;
        this->paperAttack = Attack;
        this->scissorsAttack = Attack;
        this->Defence = Defence;
        this->rockDefence = Defence;
        this->paperDefence = Defence;
        this->scissorsDefence = Defence;
        this->currentweapon = weapon();
        this->currentarmour = Armour();

        this->gold = 0;
    };

    string get_name()
    {
        return this->name;
    };
    void set_name(string name)
    {
        this->name = name;
    };

    double get_attack()
    {
        return this->Attack;
    };

    void set_attack(double Attack)
    {
        this->Attack = Attack;
    };

    double get_rockAtk()
    {
        return this->rockAttack;
    }
    void setRockAtk() // sets rock/paper/scissor atk/def by multiplying base Atk/Def by item modifier.
    {
        this->rockAttack =
            this->currentweapon.get_rockAtk() * get_attack();
    };

    void setPaperAtk()
    {
        this->rockAttack =
            this->currentweapon.get_rockAtk() * get_attack();
    };

    double get_PaperAtk()
    {
        return this->paperAttack;
    }

    void setScissorsAtk()
    {
        this->rockAttack =
            this->currentweapon.get_rockAtk() * get_attack();
    };

    double get_ScissorsAtk()
    {
        return this->scissorsAttack;
    }

    void setRockDef()
    {
        this->rockDefence = this->Defence * currentarmour.get_rockDef();
    };

    double get_rockDef()
    {
        return this->rockDefence;
    };

    void setPaperDef()
    {
        this->paperDefence = this->Defence * currentarmour.get_paperDef();
    };

    double get_paperDef()
    {
        return this->paperDefence;
    };

    void setScissorsDef()
    {
        this->scissorsDefence = this->Defence * currentarmour.get_scissorsDef();
    };

    double get_scissorsDef()
    {
        return this->scissorsDefence;
    };

    void setCurrentWeapon(weapon newWeapon)
    { // change weapon and reset RPS atk with new multipliers
        this->currentweapon = newWeapon;
        this->setRockAtk();
        this->setPaperAtk();
        this->setScissorsDef();
    }
    weapon getCurrentWeapon()
    {
        return this->currentweapon;
    }
    void setCurrentArmour(Armour newArmour)
    { // change armour and reset RPS def with new mulipliers
        this->currentarmour = newArmour;
        this->setRockDef();
        this->setScissorsDef();
        this->setPaperDef();
    }
    Armour getCurrentArmour()
    {
        return this->currentarmour;
    }

    ~Player(){};
};

#endif