#include <iostream>
#include "combat1.h"
#include <string>
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

#include "Potion.h" //predeclared potion and consumable class in player to avoid circular dependency

using namespace std;
//import header files
extern void drawHUD(Player,int);

int main() {
    combat A;
    Player* p = new Player("Test",100,20,20);
    Potion* pot = new Potion();

    /* cout<<p->get_HP()<<": Current HP\n";
    pot.useItem(p);
    cout<<p->get_HP()<<" player has this much hp now\n";
    cout<<"\n\n\n";
    cout<<pot.getDescription()<<endl<<pot.getName(); */

   
    

   
    p->addToInventory(pot);
    p->getSizeofInv();
    //cout<<p->getCurrentWeapon().get_name()<<endl;
    cout<<p->get_item(0)->getDescription()<<" selected item"<<endl;
    p->get_item(0)->useItem(p);
    /* p->setCurrentWeapon(p->getCurrentWeapon());
    cout<<p->getCurrentWeapon().get_paperAtk()<<"Paper atk of weapon"<<endl;
    cout<<p->get_attack()<<"Player atack"<<endl;
    cout<<p->get_paperAtk(); */
    
    cout<<"used item"<<endl;
    cout<<p->get_HP();
    //push a potion the inventory


   
/* int index=0;
//it is an iterator. This code with go though every element in the vector
for (auto it : inventory) {
        
        cout << "item name " << it->getName()<<endl;
        };


//use item from inventory
 

            */
    

}