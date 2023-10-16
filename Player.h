#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;
#include "Weapon.h"
#include "Armour.h"
#include "Actor.h"
#include "Item.h"
#include "vector"
#include "Consumable.h"
//forward declare these to avoid circular declaration
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
    //The inventory is a vector that can contain any number of pointers to consumables.
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
        setCurrentArmour(getCurrentArmour());     
    };

    
    

    double get_attack()
    {
        return Attack;
    };

    

    void set_attack(double argAttack)
    {
        Attack = argAttack;
    };

    double get_defense()
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
        paperAttack = currentweapon.get_paperAtk() * Attack;
    };

    

    void set_scissorsAtk()
    {
        scissorsAttack = currentweapon.get_scissorsAtk() * Attack;
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
        
        currentweapon = newWeapon;
        
        //cout << newWeapon.get_name() << endl;

        set_rockAtk();
         set_paperAtk();
         set_scissorsDef();
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
        cout<<inventory.size()<<": Size of inv \n";
    }

    Consumable* get_item(int index){
        //returns a pointer to an item at index position in the inventory
        return this->inventory[index];

    };

    void removeItem(int index){
        this->inventory.erase(inventory.begin()+index);
    }

     
     void display(){

    if (this->inventory.empty())
    {
        cout<<"No items in inventory"<<endl;
    }
    else
    {
        int i =0;
     for (Consumable* ptr : inventory) {
        cout<<i<<" "<<ptr->getName()<<endl;
        i++;
    }
     }

     }

    

    /* void useInvItem(int index){
        inventory.at(index)->useItem(this);
    } */

    ~Player(){};
};

#endif