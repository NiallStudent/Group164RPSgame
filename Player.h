#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include "Weapon.h"
#include "Armour.h"
#include "Actor.h"
#include "Item.h"
#include "vector"
class Consumable;
class Potion;
class Bomb;


class Player :public Actor
{
private:
   
    weapon currentweapon;
    Armour currentarmour;
    double Attack;
    double Defence;
    vector<Consumable*> inventory;
    

public:

    

    Player():Player("DefaultPlayerName",100,20,20){}
    
    Player(string argname, int argHP, int argAttack, int ArgDefence):Actor(argname,argHP)
    {
        
        Attack=argAttack;
        Defence=ArgDefence;
        inventory= {};
        currentweapon= weapon();
        currentarmour=Armour();
        setCurrentWeapon(getCurrentWeapon());
        

        
        
        
        //Need to add inventory attribute

        
    };

    
    

    double get_attack()
    {
        return Attack;
    };

    

    void set_attack(double argAttack)
    {
        Attack = argAttack;
    };

    double get_defene()
    {
        return Defence;
    };

    void set_defence(double argDefence)
    {
        Defence = argDefence;
    };

   
    
    void set_rockAtk() // sets rock/paper/scissor atk/def by multiplying base Atk/Def by item modifier.
    {
        rockAttack = currentweapon.get_rockAtk() * Attack;
    };

    void set_paperAtk()
    {
        rockAttack = currentweapon.get_rockAtk() * Attack;
    };

    

    void set_scissorsAtk()
    {
        rockAttack = currentweapon.get_rockAtk() * Attack;
    };

   

    void set_rockDef()
    {
        rockDefence = Defence * currentarmour.get_rockDef();
    };

    

    void set_paperDef()
    {
        paperDefence = Defence * currentarmour.get_paperDef();
    };

   

    void set_scissorsDef()
    {
        scissorsDefence = Defence * currentarmour.get_scissorsDef();
    };

   

    void setCurrentWeapon(weapon newWeapon)
    { // change weapon and reset RPS atk with new multipliers
        cout << "lol" << endl;
        currentweapon = newWeapon;
        cout << "lol2" << endl;
        cout << newWeapon.get_name() << endl;

        set_rockAtk();
        // set_paperAtk();
        // set_scissorsDef();
    }

    weapon getCurrentWeapon()
    {
        return currentweapon;
    }
    void setCurrentArmour(Armour newArmour)
    { // change armour and reset RPS def with new mulipliers
        currentarmour = newArmour;
        set_rockDef();
        set_scissorsDef();
        set_paperDef();
    }
    Armour getCurrentArmour()
    {
        return currentarmour;
    }


    void addToInventory(Consumable* newItem){
        inventory.push_back(newItem);
    }

    void getSizeofInv(){
        cout<<inventory.size()<<"Size of inv \n";
    }

    Consumable* get_item(int index){
        return this->inventory[index];

    };

    /* void useInvItem(int index){
        inventory.at(index)->useItem(this);
    } */

    ~Player(){};
};

#endif