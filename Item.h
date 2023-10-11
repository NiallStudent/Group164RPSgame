#ifndef ITEM_H
#define ITEM_H

#include <iostream>
using namespace std;

class Item //Base class for 
{
protected:
    int ID; // Could use this for tables for randomisers.
            // e.g.: 1x for weapons, 2x for armour, 3x for items
            //When making weapons/armour, remove the current ID for the possible rewards the player could get
            //When gaining consumable items, if an item with that ID is already in the inventory add one to the amount the player has.
    string name;
    string description;
    
public:
    Item():Item(000,"defaultItem","DefaultItemDescription"){};
    Item(int initID ,string initname, string initdescription){ //in future, auto generate id 
        ID=initID;
        name=initname;
        description=initdescription;
        
    };
    ~Item(){};

    //only use getters. Should not be able to change item base stats once they are made;
    string getName(){
        return name;
    };

    string getDescription(){
        return description;
    };

    int getID(){
        return ID;
    }
};




#endif