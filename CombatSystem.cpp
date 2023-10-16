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

void combat::playerDmgDealt(Player _player, Enemy* _enemy) {
        int damageReduction;
    switch (playerTypeOfAttack)
    {
    case 1:
        damageReduction = _enemy->get_rockDef();
        break;
        case 2:
        damageReduction = _enemy->get_paperDef();
        break;
        case 3:
        damageReduction = _enemy->get_scissorsDef();
        break;
    
    default:
        break;
    }
    DMGDealt = (_player.get_attack() + ATKValue)*damageMultiplier;
    if (DMGDealt < 0)
    {
        DMGDealt = 0;
    }
    
    cout << "You have dealt " << DMGDealt << " damage to the enemy!" << endl;
    int newHPtotal = _enemy->get_HP() - DMGDealt;
    _enemy->set_HP(newHPtotal);
}

void combat::playerDmgTaken(Enemy _enemy, Player* _player) {
    
    int damageReduction;
    switch (enemyTypeOfAttack)
    {
    case 1:
        damageReduction = _player->get_rockDef();
        break;
        case 2:
        damageReduction = _player->get_paperDef();
        break;
        case 3:
        damageReduction = _player->get_scissorsDef();
        break;
    
    default:
        break;

        
    }
    DMGTaken = ATKValue*damageMultiplier - damageReduction;
       if (DMGTaken < 0)
    {
        DMGTaken = 0;
    }
    cout << "You have taken " << DMGTaken << " damage from the enemy!" << endl;
    int newHPtotal = _player->get_HP() - DMGTaken;
    _player->set_HP(newHPtotal);
}

// void combat::playerHPCalc(Player _player) {                 //check Player's HP
//     playerHP = _player.get_HP() - DMGTaken;
//     cout << "Player HP: " << playerHP << endl;
// }

// void combat::enemyHPCalc(Enemy _enemy) {                    //check Enemy's HP
//     enemyHP = _enemy.get_HP() - DMGDealt;
//     cout << "Enemy HP: " << enemyHP << endl;
// }

bool combat::checkWin(Enemy activeEnemy) {
    if (activeEnemy.get_HP() <= 0) {                                   // remember to set the condition to 0, 180 is only used for testing
        cout << "-----------------------------------" << endl;
        cout << "<><><><><><><><><><><><><><><><><><" << endl;
        cout << "Congratulation! You have defeated an enemy!" << endl;
        cout << "<><><><><><><><><><><><><><><><><><" << endl;
        return true;
    }
    return false;
}

bool combat::checkLose(Player activePlayer) {
    if (activePlayer.get_HP() <= 0) {                                   // remember to set the condition to 0, 180 is only used for testing
        cout << "-----------------------------------" << endl;
        cout << "<><><><><><><><><><><><><><><><><><" << endl;
        cout << "Oh no! You been defeated :(" << endl;
        cout << "<><><><><><><><><><><><><><><><><><" << endl;
        return true;
    }
    return false;
}

void combat::drawHUD(Player* activePlayer, int currentLevel){

int hudNameSpacer = 26 - activePlayer->get_name().size();                          //Used to make spacing consistent with different length names
int hudWpnSpacer = 20 - activePlayer->getCurrentWeapon().getName().size();
int hudAmrSpacer = 20 - activePlayer->getCurrentArmour().getName().size();
int rAtkInt = activePlayer->get_rockAtk();          // Same as above, but starting with a double complicates things
string rAtk = to_string(rAtkInt);                                   //convert double to int, then to string to get value length
int pAtkInt = activePlayer->get_paperAtk();         //so that can be used to determine spacing. 
string pAtk = to_string(pAtkInt);
int sAtkInt = activePlayer->get_scissorsAtk();
string sAtk = to_string(sAtkInt);
int rDefInt = activePlayer->get_rockDef();
string rDef = to_string(rDefInt);
int pDefInt = activePlayer->get_paperDef();
string pDef = to_string(pDefInt);
int sDefInt = activePlayer->get_scissorsDef();
string sDef = to_string(sDefInt);
int rAtkSpace = rAtk.size();
int pAtkSpace = pAtk.size();
int sAtkSpace = sAtk.size();
int allAtkSpace = rAtkSpace + pAtkSpace + sAtkSpace;
int rDefSpace = rDef.size();
int pDefSpace = pDef.size();
int sDefSpace = sDef.size();
int allDefSpace = rDefSpace + pDefSpace + sDefSpace;
int currentHP = activePlayer->get_HP();
if (currentHP < 0)
{
    currentHP = 0;
}

    // Creating the box
cout << "╔═════════════════════════════════════════════════════════════╗"<<endl;       //HUD is 63 wide, 2 are the walls
cout << "║ " << activePlayer->get_name();
for (int i = 0; i < hudNameSpacer; i++){cout << " ";}     //adding approrpriate spaces given name length
if (activePlayer->get_HP() < 100 ){cout << " ";}             //adding appropriate spaces given current HP
if (activePlayer->get_HP() < 10 ){cout << " ";}              //adding appropriate spaces given current HP
cout << activePlayer->get_HP() << " HP " << "                "/*16 spaces*/;
if (currentLevel < 1000){cout << " ";}                                //adding appropriate spaces given current level (breaks after level 9999)
if (currentLevel < 100){cout << " ";}
if (currentLevel < 10){cout << " ";}
cout << "Level " << currentLevel << " " << "║" << endl;
cout<<"║ Wpn: " << activePlayer->getCurrentWeapon().get_name();
for (int i = 0; i < hudWpnSpacer; i++){cout << " ";};
cout << "rATK " << rAtk << " ";
cout << "pATK " << pAtk << " ";
cout << "sATK " << sAtk;
for (int i = 0; i < 18 - allAtkSpace; i++){cout << " ";};
cout << "║";
cout << endl;
cout<<"║ Amr: " << activePlayer->getCurrentArmour().getName();
for (int i = 0; i < hudAmrSpacer; i++){cout << " ";};
cout << "rDEF " << rDef << " ";
cout << "pDEF " << pDef << " ";
cout << "sDEF " << sDef;
for (int i = 0; i < 18 - allDefSpace; i++){cout << " ";};
cout << "║";
cout << endl;
cout <<"╚═════════════════════════════════════════════════════════════╝"<< endl;
}

void combat::drawEnemyHUD(Enemy* activeEnemy, int currentLevel){

int hudNameSpacer = 26 - activeEnemy->get_name().size();                          //Used to make spacing consistent with different length names
    // Creating the box
    int currentHP = activeEnemy->get_HP();
if (currentHP < 0)
{
    currentHP = 0;
}
cout << "╔═════════════════════════════════════════════════════════════╗"<<endl;       //HUD is 63 wide, 2 are the walls
cout << "║ " << activeEnemy->get_name();
for (int i = 0; i < hudNameSpacer; i++){cout << " ";}     //adding approrpriate spaces given name length
if (activeEnemy->get_HP() < 100 ){cout << " ";}             //adding appropriate spaces given current HP
if (activeEnemy->get_HP() < 10 ){cout << " ";}              //adding appropriate spaces given current HP
cout << currentHP << " HP " << "                "/*16 spaces*/;
if (currentLevel < 1000){cout << " ";}                                //adding appropriate spaces given current level (breaks after level 9999)
if (currentLevel < 100){cout << " ";}
if (currentLevel < 10){cout << " ";}
cout << "Level " << currentLevel << " " << "║" << endl;

cout <<"╚═════════════════════════════════════════════════════════════╝"<< endl;
}


Enemy* combat::createEnemyList(){

Enemy* enemyList = new Enemy[10];

Enemy grizzlyBear1("Grizzly Bear",30,10,10,15,8,15,10,
"It looks like it's about to charge headfirst",
"It opens its arms wide and advances",
"It readies its claws and rushes at you on its hind legs",
"It looks ready to meet your next attack with its thick skull",
"It opens its arms wide and waits for your next move",
"It takes a defensive stance and readies its claws"
);

Enemy troll1("Troll", 35, 15, 10, 10, 10, 8, 15,
"It readies its club",
"You notice its hand on a length of rope",
"It gnashes its teeth",
"It readies its club",
"It takes a defensive posture and you think you spot some rope in its hand",
"You spot a glint of well polished steel");

Enemy merfolk1("Merfolk Trapper", 40, 8, 20, 12, 17, 12, 5,
"It swings the butt of its trident at you",
"It smirks at you then approaches fast",
"It points the trident straight at your chest then charges",
"It turns the flat size of its trident towards you",
"It takes a defensive posture, hand on something on its belt",
"It takes guard, its trident pointed at you");


Enemy grizzlyBear2("Grizzly Bear",30,10,10,15,8,15,10,
"It looks like it's about to charge headfirst",
"It opens its arms wide and advances",
"It readies its claws and rushes at you on its hind legs",
"It looks ready to meet your next attack with its thick skull",
"It opens its arms wide and waits for your next move",
"It takes a defensive stance and readies its claws"
);

Enemy troll2("Troll", 35, 15, 10, 10, 10, 8, 15,
"It readies its club",
"You notice its hand on a length of rope",
"It gnashes its teeth",
"It readies its club",
"It takes a defensive posture and you think you spot some rope in its hand",
"You spot a glint of well polished steel");

Enemy merfolk2("Merfolk Trapper", 40, 8, 20, 12, 17, 12, 5,
"It swings the butt of its trident at you",
"It smirks at you then approaches fast",
"It points the trident straight at your chest then charges",
"It turns the flat size of its trident towards you",
"It takes a defensive posture, hand on something on its belt",
"It takes guard, its trident pointed at you");


Enemy grizzlyBear3("Grizzly Bear",30,10,10,15,8,15,10,
"It looks like it's about to charge headfirst",
"It opens its arms wide and advances",
"It readies its claws and rushes at you on its hind legs",
"It looks ready to meet your next attack with its thick skull",
"It opens its arms wide and waits for your next move",
"It takes a defensive stance and readies its claws"
);

Enemy troll3("Troll", 35, 15, 10, 10, 10, 8, 15,
"It readies its club",
"You notice its hand on a length of rope",
"It gnashes its teeth",
"It readies its club",
"It takes a defensive posture and you think you spot some rope in its hand",
"You spot a glint of well polished steel");

Enemy merfolk3("Merfolk Trapper", 40, 8, 20, 12, 17, 12, 5,
"It swings the butt of its trident at you",
"It smirks at you then approaches fast",
"It points the trident straight at your chest then charges",
"It turns the flat size of its trident towards you",
"It takes a defensive posture, hand on something on its belt",
"It takes guard, its trident pointed at you");

Enemy knight("Dark Knight", 70, 15, 15, 20, 20, 20, 20,
"He smirks and charges, something dull in hand",
"He charges with a sinister look in his eyes",
"He smirks and charges, something shiny in hand",
"He points his shoulder guard towards you",
"He readies his sword and mace in an x shape, ready to catch your attack",
"He takes a defensive stance and you see a bright flash");
enemyList[0] = grizzlyBear1;
enemyList[1] = troll1;
enemyList[2] = merfolk1;
enemyList[3] = grizzlyBear2;
enemyList[4] = troll2;
enemyList[5] = merfolk2;
enemyList[6] = grizzlyBear3;
enemyList[7] = troll3;
enemyList[8] = merfolk3;
enemyList[9] = knight;



return enemyList;
};

