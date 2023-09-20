using namespace std;
#include"Player.h"
#include"Armour.h"
#include "Weapon.h"


void HUD(Player Player){
cout<<"=================================="<<endl;
cout<<Player.get_name()<<endl;
cout<<"Weapon: "<<Player.getCurrentWeapon().get_name()<<endl;
cout<<"Armour: "<<Player.getCurrentArmour().getName()<<endl;
//add getGold to player
cout<<"=================================="<<endl;
}