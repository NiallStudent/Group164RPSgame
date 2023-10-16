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
    //create player, enemy and items for testing.
    combat A;
    Player* p = new Player("Test",100,20,20);
    Potion* pot = new Potion();
    Bomb* bob= new Bomb();
    Enemy* en= new Enemy();
    cout<<"Player HP: "<<p->get_HP()<<endl;
    cout<<"Enemy HP: "<<en->get_HP()<<endl;
    cout<<endl;

    /* cout<<p->get_HP()<<": Current HP\n";
    pot.useItem(p);
    cout<<p->get_HP()<<" player has this much hp now\n";
    cout<<"\n\n\n";
    cout<<pot.getDescription()<<endl<<pot.getName(); */

   
    

   cout<<"displaying inventory"<<endl;
    p->display();
    p->addToInventory(pot);
    p->addToInventory(bob);
    p->getSizeofInv();
    cout<<"displaying inventory"<<endl;
    p->display();
    cout<<endl;
    cout<<p->get_item(0)->getDescription()<<endl;
    p->get_item(0)->useItem(p);
    p->removeItem(0);
    cout<<"removed an item"<<endl;
    cout<<endl;
    cout<<p->get_item(1)->getDescription()<<endl;
    p->get_item(1)->useItem(en);
    p->removeItem(1);
    cout<<"removed an item"<<endl;
    
    cout<<endl<<endl;
    
    cout<<p->get_HP()<<" player hp";
    cout<<endl;
    cout<<"enemy hp "<<en->get_HP()<<endl;
    p->getSizeofInv();
   

}