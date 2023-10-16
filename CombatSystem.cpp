#include "CombatSystem.h"
#include <string>
#include <random>
using namespace std;

combat::combat() {
}
void combat::playerAttackType(Player _player) {
    //initialize playerTypeOfAttack for while loop
    playerTypeOfAttack = 10;

    while (playerTypeOfAttack != 1 && playerTypeOfAttack != 2 && playerTypeOfAttack != 3) {
        cout << "-----------------------------------" << endl;
        cout << "Choose your type of attack: (1 for rock, 2 for paper, 3 for scissor): ";
        cin >> playerTypeOfAttack;
        switch (playerTypeOfAttack) {
        case 1:
            cout << "You performed a rock attack!" << endl;
            ATKValue = _player.get_rockAtk();
            break;
        case 2:
            cout << "You performed a paper attack!" << endl;
            ATKValue = _player.get_paperAtk();
            break;
        case 3:
            cout << "You performed a scissor attack!" << endl;
            ATKValue = _player.get_scissorsAtk();
            break;
        default:
            cout << "Invalid number, please try again!" << endl;
            ATKValue = 0;   
        }
    }
}

void combat::playerDefenceType(Player _player) {

    //initialize playerTypeOfDefence for while loop
    playerTypeOfDefence = 10;

    while (playerTypeOfDefence != 1 && playerTypeOfDefence != 2 && playerTypeOfDefence != 3) {
        cout << "-----------------------------------" << endl;
        cout << "Choose your type of defence: (1 for rock, 2 for paper, 3 for scissor): ";
        cin >> playerTypeOfDefence;
        switch (playerTypeOfDefence) {
        case 1:
            cout << "You performed a rock defence!" << endl;
            DEFValue = _player.get_rockDef();
            break;
        case 2:
            cout << "You performed a paper defence!" << endl;
            DEFValue = _player.get_paperDef();
            break;
        case 3:
            cout << "You performed a scissor defence!" << endl;
            DEFValue = _player.get_scissorsDef();
            break;
        default:
            cout << "Invalid number, please try again!" << endl;
            DEFValue = 0;   
        }
    }
}

void combat::enemyAttackType(Enemy _enemy) {
    enemyTypeOfAttack = rand() % 3 + 1;
    switch (enemyTypeOfAttack) {
        case 1:
            cout << "The enemy performed a rock attack!" << endl;
            ATKValue = _enemy.get_rockAtk();
            break;
        case 2:
            cout << "The enemy performed a paper attack!" << endl;
            ATKValue = _enemy.get_paperAtk();
            break;
        case 3:
            cout << "The enemy performed a scissor attack!" << endl;
            ATKValue = _enemy.get_scissorsAtk();
            break;
    }
}

void combat::enemyDefenceType(Enemy _enemy) {
    enemyTypeOfDefence = rand() % 3 + 1;
    switch (enemyTypeOfDefence) {
        case 1:
            cout << "The enemy performed a rock Defence!" << endl;
            DEFValue = _enemy.get_rockDef();
            break;
        case 2:
            cout << "The enemy performed a paper Defence!" << endl;
            DEFValue = _enemy.get_paperDef();
            break;
        case 3:
            cout << "The enemy performed a scissor Defence!" << endl;
            DEFValue = _enemy.get_scissorsDef();
            break;
    }
}

double combat::getDmgMultiplierFromPlayer() {
    if (playerTypeOfAttack == enemyTypeOfDefence) {
        damageMultiplier = 1;
        cout << "--> You dealt normal damage to the enemy!" << endl;
    }
    else if (((playerTypeOfAttack == 1) && (enemyTypeOfDefence == 2)) || ((playerTypeOfAttack == 2) && (enemyTypeOfDefence == 3)) || ((playerTypeOfAttack == 3) && (enemyTypeOfDefence == 1))) {
        damageMultiplier = 0.5;
        cout << "--> You hit the enemy's armour, dealth 50% less damage!" << endl;
    }
    else if (((playerTypeOfAttack == 1) && (enemyTypeOfDefence == 3)) || ((playerTypeOfAttack == 2) && (enemyTypeOfDefence == 1)) || ((playerTypeOfAttack == 3) && (enemyTypeOfDefence == 2))) {
        damageMultiplier = 2;
        cout << "--> You hit the enemy's weekness, dealt 100% more damage!" << endl;
    }
    return damageMultiplier;
}

double combat::getDmgMultiplierFromEnemy() {
    if (playerTypeOfDefence == enemyTypeOfAttack) {
        damageMultiplier = 1;
        cout << "--> The enemy dealt normal damage to you!" << endl;
    }
    else if (((playerTypeOfDefence == 1) && (enemyTypeOfAttack == 2)) || ((playerTypeOfDefence == 2) && (enemyTypeOfAttack == 3)) || ((playerTypeOfDefence == 3) && (enemyTypeOfAttack == 1))) {
        damageMultiplier = 2;
        cout << "--> The enemy shredded your armor, received 100% more damage!" << endl;
    }
    else if (((playerTypeOfDefence == 1) && (enemyTypeOfAttack == 3)) || ((playerTypeOfDefence == 2) && (enemyTypeOfAttack == 1)) || ((playerTypeOfDefence == 3) && (enemyTypeOfAttack == 2))) {
        damageMultiplier = 2;
        cout << "--> The enemy's attack was parried, recieved 50% less damage!" << endl;
    }
    return damageMultiplier;
}

void combat::playerDmgDealt(Player _player) {
    // need to modify get_attack() in Actor.h
    DMGDealt = (_player.get_attack() + ATKValue)*damageMultiplier;
    cout << "You have dealt " << DMGDealt << "damage to the enemy!" << endl;
}

void combat::playerDmgTaken(Enemy _enemy) {
    DMGTaken = ATKValue*damageMultiplier;
    cout << "You have taken " << DMGTaken << " damage from the enemy!" << endl;

}

void combat::playerHPCalc(Player _player) {                 //check Player's HP
    playerHP = _player.get_HP() - DMGTaken;
    cout << "Player HP: " << playerHP << endl;
}

void combat::enemyHPCalc(Enemy _enemy) {                    //check Enemy's HP
    enemyHP = _enemy.get_HP() - DMGDealt;
    cout << "Enemy HP: " << enemyHP << endl;
}

bool combat::checkWin(RewardSystem _reward) {
    if (enemyHP <= 199) {                                   // remember to set the condition to 0, 180 is only used for testing
        cout << "-----------------------------------" << endl;
        cout << "<><><><><><><><><><><><><><><><><><" << endl;
        cout << "Congratulation! You have defeated an enemy!" << endl;
        cout << "<><><><><><><><><><><><><><><><><><" << endl;
        return true;
    }
    return false;
}