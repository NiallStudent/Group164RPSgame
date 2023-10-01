#include <iostream>
#include "Player.h"
#include "hud.h"
#include "Armour.h"
#include "Weapon.h"
#include "Item.h"
#include <vector>
#include "potion.h"

using namespace std;

int main() {

    Player p("Niall",100,20,20);
    cout<<"Player name: "<<p.get_name()<<endl;
    cout<<"Weapon name: "<<p.getCurrentWeapon().get_name()<<endl;

    Item* item1=new Item(000,"Item 1","This is a test item 1");
    Item* item2=new Item(000,"Item 2","This is a test item 2");
    cout<<item1->getName();

    p.addItem(item1);
    p.addItem(item2);

    p.listItems();

    cout<<p.getItem(0);

    cout<<"using potion"<<endl;

    potion pot;
    pot.heal(p);
    
    
    
    return 0;
}
