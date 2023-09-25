#include "inventory.h"
#include <iostream>
using namespace std;

int main(){
    
    Item* item1 = new Item("item 1");
    Item* item2 = new Item("item 2");

    vector<Item*> inventory;
    inventory.push_back(item1);
    inventory.push_back(item2);

   

    int i=0;


cout<<"no of items in inventory: "<<inventory.size()<<endl;

Item* item3= new Item("item 3");

inventory.push_back(item3);

cout<<"no of items in inventory: "<<inventory.size()<<endl;

inventory.pop_back();

cout<<"no of items in inventory: "<<inventory.size()<<endl;

int index=0;

for (auto it : inventory) {
        
        cout << "item name" << it->getName()<<endl;
        };
           return 0;   
    

    }
   

