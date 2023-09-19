#include <iostream>
using namespace std;
#include "Weapon.h"
#include "Armour.h"
#include "Player.h"

int main(){
    Player player("Niall",100,20,30);
    weapon w(101,"Better Sword","This sword is better than the default sword",4,4,4);
    //Armour a;

    cout<<player.getCurrentWeapon().get_name()<<endl;

    player.setCurrentWeapon(w);
    cout<<player.getCurrentWeapon().get_name()<<endl;
    

   

    

};