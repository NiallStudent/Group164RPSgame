#include <iostream>
#include <string>
#include "combat1.h"
using namespace std;
#include "Player.h"
#include "Enemy.h"

combat::combat() {

}

int combat::playerAttack(Player) {
    cout << "Choose your type of attack: (1 for rock, 2 for paper, 3 for scissor)" << endl;
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
        cout << "Invalid number, please try again" << endl;
        return 0;
        break;
    }
}

int combat::playerDefense() {
    cout << "Choose your type of defense: (1 for rock, 2 for paper, 3 for scissor)" << endl;
    cin >> playerTypeOfDefense;
    switch (playerTypeOfDefense) {
    case 1:
        cout << "You performed a rock defense!" << endl;
        return 1;
        break;
    case 2:
        cout << "You performed a paper defense!" << endl;
        return 2;
        break;
    case 3:
        cout << "You performed a scissor defense!" << endl;
        return 3;
        break;
    default:
        cout << "Invalid number, please try again" << endl;
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

int combat::enemyDefense(Enemy) {
    srand(time(0));
    enemyTypeOfDefense = rand() % 3 + 1;
    switch (enemyTypeOfDefense) {
        case 1:
            cout << "The enemy performed a rock defense!" << endl;
            break;
        case 2:
            cout << "The enemy performed a paper defense!" << endl;
            break;
        case 3:
            cout << "The enemy performed a scissor defense!" << endl;
            break;
    }
    return enemyTypeOfDefense;
}

int combat::getDmgMultiplierFromPlayer(Player player, Enemy enemy) {
    cout<<"Player atk type"<<playerTypeOfAttack<<endl;
    cout<<"Enemy def type"<<enemyTypeOfDefense<<endl;
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

int combat::getPlayerCurrentHP() {
    return 1;
}

int combat::getEnemyCurrentHP() {
    return 1;
}

void combat::playerDealtDmg(Player p, Enemy e){
    cout<<"calculating dmg";
    cout<<"Damage is being multiplied by "<<damageMultiplier;
    double playerAtkCalc;
    double enemyDefCalc;
    //Evaluate player atk and enemy def option. get appropriate stat and use for dmg calc
    switch (playerTypeOfAttack)
    {
    case 1:
        playerAtkCalc=p.get_rockAtk();
        break;
    
    
    case 2:
        playerAtkCalc=p.get_paperAtk();
        break;

    case 3:
        playerAtkCalc=p.get_scissorsAtk();
        cout<<"scissor atk is "<<p.get_scissorsAtk()<<endl;
        break;
    
    default:
        break;
    }
    cout<<"Player is attaking for "<<playerAtkCalc<<" base dmg"<<endl;

    switch (enemyTypeOfDefense)
    {
    case 1:
        enemyDefCalc=e.get_rockDef();
        break;

    case 2:
        enemyDefCalc=e.get_paperDef();
        break;

    case 3:
        enemyDefCalc=e.get_scissorsDef();
        break;
    
    default:
        break;
    }

    cout<<"enemy defends for "<<enemyDefCalc<<" base def"<<endl;

    //Calcualte dmg. If dmg is <0, do at least 1 dmg;
    double dmg = 0;
    if (damageMultiplier*(playerAtkCalc-enemyDefCalc)<=0)
    {
        dmg=1;
    }
    else
    {
        dmg=damageMultiplier*(playerAtkCalc-enemyDefCalc);
    }
    
    //change the enemy hp
    cout<<"dmg to be delt "<<dmg<<endl;
    cout<<"Current enemy hp "<<e.get_HP()<<endl;
    int newEnemyHP=e.get_HP()-dmg;
    e.set_HP(newEnemyHP);


};