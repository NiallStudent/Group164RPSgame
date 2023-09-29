#include <iostream>
#include "combat1.h"
#include <string>
using namespace std;

int main() {
    combat A;


    cout << "It's your turn!" << endl;
    cout << "" << endl;
    cout << "" <<endl;
    A.playerAttack();
    A.enemyDefense();
    A.getDmgMultiplierFromPlayer();

    //calc dmg
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