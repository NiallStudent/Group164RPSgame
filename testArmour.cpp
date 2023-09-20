#include <iostream>
using namespace std;
// #include<windows.h> doesnt work??
// #include <conio.h> Windows only
#include "Weapon.h"
#include "Armour.h"
#include "Player.h"
#include "hud.h"
#include <stdio.h>

int main()
{

    Player player("Niall", 100, 20, 30);

    HUD(player);

    cout << "did this work?" << endl;

    system("clear");

    cout<<"is this still here?"<<endl;

   // Armour a2(21, "Better armour", "This armour is twice as good as the default", 4, 4, 4);

    //player.setCurrentArmour(a2);

    //HUD(player);

    // std::cout<<"\033[31;1;4mTook 999dmg\033[0m";
};