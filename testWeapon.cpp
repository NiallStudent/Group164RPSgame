#include <iostream>
using namespace std;
#include "Weapon.h"
#include "Armour.h"
#include "Player.h"
#include "Enemy.h"

int main(){
    Player p;
    cout<<p.get_name()<<endl;   
    cout<<p.getCurrentWeapon().get_name()<<endl<<endl;

    Enemy e;
    cout<<e.get_name()<<endl;
    cout<<e.get_PaperAtk()<<endl;

    
    
    

};