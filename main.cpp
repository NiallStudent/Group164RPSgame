#include <iostream>
#include "combat1.h"
#include <string>
#include "Player.h"
#include "Enemy.h"
using namespace std;

extern void drawHUD(Player,int);

int main() {

cout << "~=Welcome to RPS Hero=~" << endl; 
int currentLevel = 1; //level system initialiser 

string playerName;                                  //creating the character name, checking length is between 1 and 16 characters long
bool nameLengthCheck = false;
while (nameLengthCheck == false){                   //loops until there is a valid name
cout << "enter your name ( minimum 1, maximum 16 characters)" << endl;
cin >> playerName;
if (playerName.size() < 17 && playerName.size() > 0) //checking name is between 1 and 16 characters long
    {
    nameLengthCheck = true;
    }
else {
    cout << "Please enter a valid name" << endl;
    }
}


    combat combatSystem;
    Player activePlayer(playerName,100,10,10);

    cout << activePlayer.get_name() << " has " << activePlayer.get_HP() << "HP" << endl;
    Enemy e("enemy", 100,10, 10, 10, 10, 10, 10, "lmao", "lmao2", "lmao3", "wewlad", "wewlad2", "lmao22");
    weapon w;
    Armour a(21, "lmao", "nope", 10,10,10);
    cout << "Made generic stuff" << endl;
    activePlayer.setCurrentWeapon(w);
        cout << "testlol" << activePlayer.getCurrentWeapon().get_paperAtk() << endl;
        cout << "TEST1" << activePlayer.getCurrentArmour().get_paperDef() << endl;
    activePlayer.setCurrentArmour(a);
        cout << "TEST2" << activePlayer.getCurrentArmour().get_paperDef() << endl;
bool combatLoop = true;

while (combatLoop == true)
{
    cout << "It's your turn!" << endl;
    cout << "" << endl;
    cout << "" <<endl;
    combatSystem.playerAttack(activePlayer);
    combatSystem.enemyDefense(e);
    combatSystem.getDmgMultiplierFromPlayer(activePlayer,e);

    combatSystem.playerDealtDmg(activePlayer,e);
    //check if enemy is alive
    cout << "you have " << activePlayer.get_HP() << "HP" << endl;

    drawHUD(activePlayer,20);

    cout << "It's enemy's turn!" << endl;
    cout << "" << endl;
    cout << "" <<endl;
    combatSystem.playerDefense();
    combatSystem.enemyAttack();
    combatSystem.getDmgMultiplierFromEnemy();

    //cout << "you have " << activePlayer.get_HP() << "HP" << endl;
    drawHUD(activePlayer,20);
    cout << e.get_name() << " has " << e.get_HP() << "HP remaining" << endl; 
    //calc dmg
    //check if player is alive
}
    return 0;
}