#include <iostream>
#include "Player.h"
#include "combat1.h"
#include <string>

#include "Enemy.h"
#include "Item.h"
#include "Consumable.h"
#include "Potion.h"
using namespace std;

extern void drawHUD(Player,int);

int main() {
    combat A;
    Player* p = new Player("Testicle",100,20,20);
    Potion pot;

    /* cout<<p->get_HP()<<": Current HP\n";
    pot.useItem(p);
    cout<<p->get_HP()<<" player has this much hp now\n";
    cout<<"\n\n\n";
    cout<<pot.getDescription()<<endl<<pot.getName(); */

    Consumable* item1 = new Potion();
    

   
    p->addToInventory(item1);
    

   

   /*  int i=0;


cout<<"no of items in inventory: "<<p->getInventory().size();







int index=0;

for (auto it : p->getInventory()) {
        
        cout << "item name" << it->getName()<<endl;
        }; */
           return 0;   

           
    

}