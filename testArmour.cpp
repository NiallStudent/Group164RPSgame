#include <iostream>
using namespace std;
#include "Weapon.h"
#include "Armour.h"
#include "Player.h"

int main(){
    Player player("Niall",100,20,30);
    Armour a;

    player.setPaperDef();
    cout<<player.getCurrentArmour().getName()<<endl;
    

    Armour a2(21,"Better armour","This armour is twice as good as the default",4,4,4);

    player.setCurrentArmour(a2);
    cout<<player.getCurrentArmour().getName()<<endl;
};