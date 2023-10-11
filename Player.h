#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include "Weapon.h"
#include "Armour.h"
#include "Actor.h"

class Player :public Actor
{
private:
   
    weapon currentweapon;
    Armour currentarmour;
    double Attack;
    double Defence;

public:

    Player():Player("DefaultPlayerName",100,20,20){}
    
    Player(string argname, int argHP, int argAttack, int ArgDefence):Actor(argname,argHP)
    {
        
        this->Attack=argAttack;
        this->Defence=ArgDefence;
        
        
        //Need to add inventory attribute

        
    };

    
    

    double get_attack()
    {
        return this->get_attack();
    };

    void set_attack(double Attack)
    {
        this->Attack = Attack;
    };

   
    
    void set_rockAtk() // sets rock/paper/scissor atk/def by multiplying base Atk/Def by item modifier.
    {
        this->rockAttack =
            this->currentweapon.get_rockAtk() * get_attack();
    };

    void set_paperAtk()
    {
        this->rockAttack =
            this->currentweapon.get_rockAtk() * get_attack();
    };

    

    void set_scissorsAtk()
    {
        this->rockAttack =
            this->currentweapon.get_rockAtk() * get_attack();
    };

   

    void set_rockDef()
    {
        this->rockDefence = this->Defence * currentarmour.get_rockDef();
    };

    

    void set_paperDef()
    {
        this->paperDefence = this->Defence * currentarmour.get_paperDef();
    };

   

    void set_scissorsDef()
    {
        this->scissorsDefence = this->Defence * currentarmour.get_scissorsDef();
    };

   

    void setCurrentWeapon(weapon newWeapon)
    { // change weapon and reset RPS atk with new multipliers
        this->currentweapon = newWeapon;
        this->set_rockAtk();
        this->set_paperAtk();
        this->set_scissorsDef();
    }
    weapon getCurrentWeapon()
    {
        return this->currentweapon;
    }
    void setCurrentArmour(Armour newArmour)
    { // change armour and reset RPS def with new mulipliers
        this->currentarmour = newArmour;
        this->set_rockDef();
        this->set_scissorsDef();
        this->set_paperDef();
    }
    Armour getCurrentArmour()
    {
        return this->currentarmour;
    }

    ~Player(){};
};

#endif