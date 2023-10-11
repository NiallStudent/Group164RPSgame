#include <iostream>
#include "combat1.h"
#include <string>
#include "Player.h"
#include "Enemy.h"
using namespace std;

int main() {
    combat A;
    Player p;
    Enemy e;
    weapon w;
    Armour a;
    p.setCurrentWeapon(w);
    p.setCurrentArmour(a);


    cout << "It's your turn!" << endl;
    cout << "" << endl;
    cout << "" <<endl;
    A.playerAttack(p);
    A.enemyDefense(e);
    A.getDmgMultiplierFromPlayer(p,e);

    A.playerDealtDmg(p,e);
    //check if enemy is alive

    cout << "It's enemy's turn!" << endl;
    cout << "" << endl;
    cout << "" <<endl;
    A.playerDefense();
    A.enemyAttack();
    A.getDmgMultiplierFromEnemy();

    //calc dmg
    //check if player is alive

    return 0;
}