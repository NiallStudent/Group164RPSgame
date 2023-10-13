#include <iostream>
#include <string>
#include "combat1.h"
using namespace std;

combat::combat() {

}

int combat::playerAttack() {
    cout << "Choose your type of attack: (1 for rock, 2 for paper, 3 for scissor): " << endl;
    cin >> playerTypeOfAttack;
    switch (playerTypeOfAttack) {
    case 1:
        cout << "You performed a rock attack!" << endl;
        return 1;
        break;
    case 2:
        cout << "You performed a paper attack!" << endl;
        return 2;
        break;
    case 3:
        cout << "You performed a scissor attack!" << endl;
        return 3;
        break;
    default:
        cout << "Invalid number, please try again!" << endl;
        return 0;
        break;
    }
}

int combat::playerDefense() {
    cout << "Choose your type of defence: (1 for rock, 2 for paper, 3 for scissor): " << endl;
    cin >> playerTypeOfDefense;
    switch (playerTypeOfDefense) {
    case 1:
        cout << "You performed a rock defence!" << endl;
        return 1;
        break;
    case 2:
        cout << "You performed a paper defence!" << endl;
        return 2;
        break;
    case 3:
        cout << "You performed a scissor defence!" << endl;
        return 3;
        break;
    default:
        cout << "Invalid number, please try again!" << endl;
        return 0;
        break;
    }
}

int combat::enemyAttack() {
srand(time(0));
    enemyTypeOfAttack = rand() % 3 + 1;
    switch (enemyTypeOfAttack) {
        case 1:
            cout << "The enemy performed a rock attack!" << endl;
            break;
        case 2:
            cout << "The enemy performed a paper attack!" << endl;
            break;
        case 3:
            cout << "The enemy performed a scissor attack!" << endl;
            break;
    }
    return enemyTypeOfAttack;
}

int combat::enemyDefense() {
    srand(time(0));
    enemyTypeOfDefense = rand() % 3 + 1;
    switch (enemyTypeOfDefense) {
        case 1:
            cout << "The enemy performed a rock defence!" << endl;
            break;
        case 2:
            cout << "The enemy performed a paper defence!" << endl;
            break;
        case 3:
            cout << "The enemy performed a scissor defence!" << endl;
            break;
    }
    return enemyTypeOfDefense;
}

int combat::getDmgMultiplierFromPlayer() {
    if (playerTypeOfAttack == enemyTypeOfDefense) {
        damageMultiplier = 1;
        cout << "Your ATK was on par with the enemy DEF, dealt 100% damage to the enemy!" << endl;
    }
    else if (((playerTypeOfAttack == 1) && (enemyTypeOfDefense == 2)) || ((playerTypeOfAttack == 2) && (enemyTypeOfDefense == 3)) || ((playerTypeOfAttack == 3) && (enemyTypeOfDefense == 1))) {
        damageMultiplier = 0.5;
        cout << "Your ATK was weaker than the enemy DEF, dealt 50% less damage to the enemy!" << endl;
    }
    else if (((playerTypeOfAttack == 1) && (enemyTypeOfDefense == 3)) || ((playerTypeOfAttack == 2) && (enemyTypeOfDefense == 1)) || ((playerTypeOfAttack == 3) && (enemyTypeOfDefense == 2))) {
        damageMultiplier = 2;
        cout << "Your ATK was stronger the enemy DEF, dealt 200% damage to the enemy!" << endl;
    }
    return damageMultiplier;
}

int combat::getDmgMultiplierFromEnemy() {
    if (playerTypeOfDefense == enemyTypeOfAttack) {
        damageMultiplier = 1;
        cout << "Your DEF was on par with the enemy ATK, dealt 100% damage to the you!" << endl;
    }
    else if (((playerTypeOfDefense == 1) && (enemyTypeOfAttack == 2)) || ((playerTypeOfDefense == 2) && (enemyTypeOfAttack == 3)) || ((playerTypeOfDefense == 3) && (enemyTypeOfAttack == 1))) {
        damageMultiplier = 0.5;
        cout << "Your DEF was stronger than the enemy ATK, dealt 50% less damage to you!" << endl;
    }
    else if (((playerTypeOfDefense == 1) && (enemyTypeOfAttack == 3)) || ((playerTypeOfDefense == 2) && (enemyTypeOfAttack == 1)) || ((playerTypeOfDefense == 3) && (enemyTypeOfAttack == 2))) {
        damageMultiplier = 2;
        cout << "Your attack was weaker the enemy defense, dealt 200% damage to you!" << endl;
    }
    return damageMultiplier;
}

void combat::playerDealtDmg() {
    cout << "You have dealt " << //player.atk*damageMultiplier*player.weapon << " to the enemy!" << endl;
    //enemy.hp = enemy.hp - player.atk*damageMultiplier*player.weapon
}

void combat::enemyDealtDmg() {
    cout << "Enemy has dealt " << //enemy.atk*damageMultiplier << " to you!" << endl;
    //player.hp = player.hp - enemy.atk*damageMultiplier
}

void combat::checkWin() {
    // if enemy.health == 0 {
        cout << "Congratulation! You have defeated an enemy!"

        //Condition if not the last enemy -> choose reward
        reward();
    // }
}

void combat::checkLose() {
    // if player.health == 0 {
        cout << "You died! Game over!" << endl;
        break;
    }
