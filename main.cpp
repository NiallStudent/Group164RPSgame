#include <iostream>
#include "combat.h"
#include <string>
#include "Player.h"
#include "Enemy.h"
using namespace std;

extern void drawHUD(Player,int);

int main() {
    combat A;
    Player p("Namelol",100,100,100);
     cout << p.get_name() << " has " << p.get_HP() << "HP" << endl;
    Enemy e("enemy", 100,10, 10, 10, 10, 10, 10, "lmao", "lmao2", "lmao3", "wewlad", "wewlad2", "lmao22");
    weapon w;
    Armour a(21, "lmao", "nope", 10,10,10);
    cout << "Made generic stuff" << endl;
    p.setCurrentWeapon(w);
        cout << "testlol" << p.getCurrentWeapon().get_paperAtk() << endl;
        cout << "TEST1" << p.getCurrentArmour().get_paperDef() << endl;
    p.setCurrentArmour(a);
        cout << "TEST2" << p.getCurrentArmour().get_paperDef() << endl;
bool combatLoop = true;

while (combatLoop == true)
{
    cout << "It's your turn!" << endl;
    cout << "" << endl;
    cout << "" <<endl;
    A.playerAttack(p);
    A.enemyDefense(e);
    A.getDmgMultiplierFromPlayer(p,e);

    A.playerDealtDmg(p,e);
    //check if enemy is alive
    cout << "you have " << p.get_HP() << "HP" << endl;

    drawHUD(p,20);

    cout << "It's enemy's turn!" << endl;
    cout << "" << endl;
    cout << "" <<endl;
    A.playerDefense();
    A.enemyAttack();
    A.getDmgMultiplierFromEnemy();

    //cout << "you have " << p.get_HP() << "HP" << endl;
    drawHUD(p,20);
    cout << e.get_name() << " has " << e.get_HP() << "HP remaining" << endl; 
    //calc dmg
    //check if player is alive
}
    return 0;
}