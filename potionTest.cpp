#include <iostream>
#include "combat1.h"
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

#include "Potion.h" //predeclared potion and consumable class in player to avoid circular dependency
#include "Bomb.h"
using namespace std;
//import header files
extern void drawHUD(Player,int);

int main() {
    combat A;
    Player* p = new Player("Test",100,20,20);
    Potion* pot = new Potion();
    Bomb* bob= new Bomb();
    Enemy* en= new Enemy();

    /* cout<<p->get_HP()<<": Current HP\n";
    pot.useItem(p);
    cout<<p->get_HP()<<" player has this much hp now\n";
    cout<<"\n\n\n";
    cout<<pot.getDescription()<<endl<<pot.getName(); */

   
    

   
    p->addToInventory(pot);
    p->addToInventory(bob);
    p->getSizeofInv();cout<<"no of items in inventory";
    //cout<<p->getCurrentWeapon().get_name()<<endl;
    cout<<p->get_item(0)->getDescription()<<" selected item"<<endl;
    p->get_item(0)->useItem(p);
    cout<<p->get_item(1)->getDescription()<<endl;
    p->get_item(1)->useItem(en);
    /* p->setCurrentWeapon(p->getCurrentWeapon());
    cout<<p->getCurrentWeapon().get_paperAtk()<<"Paper atk of weapon"<<endl;
    cout<<p->get_attack()<<"Player atack"<<endl;
    cout<<p->get_paperAtk(); */
    
    cout<<"used item"<<endl;
    cout<<p->get_HP()<<" player hp";
    cout<<endl;
    cout<<"enemy hp "<<en->get_HP();
    //push a potion the inventory


   
/* int index=0;
//it is an iterator. This code with go though every element in the vector
for (auto it : inventory) {
        
        cout << "item name " << it->getName()<<endl;
        };


//use item from inventory
 

            */
    

}