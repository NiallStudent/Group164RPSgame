#include <iostream>
#include "CombatSystem.h"
#include <string>
#include "Player.h"
#include "Enemy.h"
using namespace std;


int main() {

cout << "~=Welcome to RPS Hero=~" << endl; 
int currentLevel = 1; //level system initialiser 

string playerName;                                  //creating the character name, checking length is between 1 and 16 characters long
bool nameLengthCheck = false;
while (nameLengthCheck == false){                   //loops until there is a valid name
cout << "Enter your name ( minimum 1, maximum 16 characters)" << endl;
//cin >> playerName;
getline(cin, playerName);
if (playerName.size() < 17 && playerName.size() > 0) //checking name is between 1 and 16 characters long
    {
    nameLengthCheck = true;
    }
else {
    cout << "Please enter a valid name" << endl;
    }
}
cout << "Get ready for battle!" << endl;
    Player activePlayer(playerName,100,100,100);                                //initialising classes that will be used during combat loop
    weapon baseWeapon(100,"Mundane Club", "Not much to look at",4,3,3);
    Armour baseArmour(101, "Mundane Armour", "Not much to look at",3,3,3);
    weapon sword(102, "Sword of Justice", "It's shiny",5,5,8);
    weapon club(103, "Club of doom", "Slow but painful",10,4,4);
    weapon whip(104, "Whip of pain", "Green and spiky!", 4, 8, 6);
    Armour Plate(105, "Plate Armour", "Cumbersome Plate Armour", 8, 4, 6);
    Armour Cloth(106, "Cloth Armour", "Comfy and easy to wear", 4, 10, 4);
    Armour Chainmail(107, "Chainmail", "Protects from blades", 4, 4, 10);
    activePlayer.setCurrentArmour(baseArmour);
    activePlayer.setCurrentWeapon(baseWeapon);
    combat combatSystem;
    RewardSystem rewards1;
    RewardSystem rewards2;
    RewardSystem rewards3;
    rewards1.generateRewards(1);
    rewards2.generateRewards(2);
    rewards3.generateRewards(3);
    bool isArmourChoiceValid = false;
    bool isWpnChoiceValid = false;



Enemy* enemyRoster = combatSystem.createEnemyList();


 bool isGameOver = false; 
 bool isBattleOver = false;
 bool isDefeated = false;
 double combatMultiplier = 1;
 bool isAttacking = true;
 bool isInventoryChoiceValid = false;
 int inventoryChoice = 10;

   while (isGameOver == false)                                  //loops until defeat or all enemies defeated
   {
    Enemy* activeEnemy = &enemyRoster[currentLevel-1];          //selects enemy for this round of combat based on current level
    cout << "Enemy #" << currentLevel <<" is a " << activeEnemy->get_name() << ". Get ready to face it!" << endl;
    combatSystem.drawHUD(&activePlayer, currentLevel);          //draws player and enemy information
    combatSystem.drawEnemyHUD(activeEnemy, currentLevel);
     while (isBattleOver == false)                              //loops until enemy or player defeated
     {
        if(activePlayer.isInventoryEmpty()){isAttacking = true;}
        else {
            isInventoryChoiceValid = false;
           while (isInventoryChoiceValid == false)
           {
            cout << "Do you want to use an item? 1 for yes, 2 for no" << endl;
            cin >> inventoryChoice;
            switch (inventoryChoice)
            {
            case 1:
               //inventory code here//


               isAttacking = false;
               isInventoryChoiceValid = true; 
                break;
            case 2:


                isAttacking = true;
                isInventoryChoiceValid = true;
                break;
            default:
            cout << "Please enter a valid response";
                break;
            }
           }
        }


        combatSystem.playerAttackType(activePlayer);                        //asks player for attack type
        combatSystem.enemyDefenceType(*activeEnemy);                        //generates random enemy attack
        combatSystem.getDmgMultiplierFromPlayer();                          //determines damange bonus/penalty
        combatSystem.playerDmgDealt(activePlayer, activeEnemy);             //damage calculation and application
        combatSystem.drawHUD(&activePlayer, currentLevel);
        combatSystem.drawEnemyHUD(activeEnemy, currentLevel);
        if (combatSystem.checkWin(*activeEnemy))
        {
            isBattleOver = true;
            cout << "You have defeated the " << activeEnemy->get_name() << endl;
        }
        else{
            combatSystem.enemyAttackType(*activeEnemy);                             //same as above but roles reversed
            combatSystem.playerDefenceType(activePlayer);
            combatSystem.getDmgMultiplierFromEnemy();
            combatSystem.playerDmgTaken(*activeEnemy, &activePlayer);
            combatSystem.drawHUD(&activePlayer, currentLevel);
            combatSystem.drawEnemyHUD(activeEnemy, currentLevel);
        }

          if (combatSystem.checkLose(activePlayer))                             //checks if the player is defeated
        {
            isDefeated = true;
            isBattleOver = true;
            isGameOver = true;
        }
        
     }
     
    switch (currentLevel)                                           //reward system based on number of enemies defeated
     {
    case 1:
    rewards1.displayRandomRewards(&activePlayer);
    break;
    case 2:
    rewards1.displayRandomRewards(&activePlayer);
    break;
    case 3:
    rewards1.displayRandomRewards(&activePlayer);
    break;
    case 4:
    
        while (isWpnChoiceValid == false)
        {
        cout << "pick a weapon! 1 for a Club, 2 for a Whip, 3 for a Sword!"<< endl;
            int wpnChoice;
            cin >> wpnChoice;
        switch (wpnChoice)
        {
        case 1:
            activePlayer.setCurrentWeapon(club);
            isWpnChoiceValid = true;
         break;

        case 2:
            activePlayer.setCurrentWeapon(whip);
            isWpnChoiceValid = true;
        break;
    
         case 3:
            activePlayer.setCurrentWeapon(sword);
            isWpnChoiceValid = true;
            break;

        default:
        cout << "Please enter a valid choice" << endl;
            break;
        }
        }
    break;
    case 5:
    rewards2.displayRandomRewards(&activePlayer);
    break;
    case 6:
    rewards2.displayRandomRewards(&activePlayer);
    break;
    case 7:
    rewards2.displayRandomRewards(&activePlayer);
    break;
    case 8:
    
    while (isArmourChoiceValid == false)
    {
    cout << "pick some Armour! 1 for Plate Armour, 2 for Cloth Armour, 3 for Chainmail"<< endl;
    int wpnChoice;
    cin >> wpnChoice;
    switch (wpnChoice)
    {
    case 1:
        activePlayer.setCurrentArmour(Plate);
        isArmourChoiceValid = true;
        break;
        
    case 2:
        activePlayer.setCurrentArmour(Cloth);
        isArmourChoiceValid = true;
        break;
    
    case 3:
        activePlayer.setCurrentArmour(Chainmail);
        isArmourChoiceValid = true;
        break;
    }
    }
    break;

    case 9:
        rewards3.displayRandomRewards(&activePlayer);
        break;
    case 10:
        isGameOver = true;
        break;
     
     default:
        break;
     }
     
     currentLevel++;


    activeEnemy = &enemyRoster[currentLevel-1];
    isBattleOver = false;

   }
if (isDefeated)
{
    cout << "GAME OVER! Thanks for playing!" << endl;
}
else  { cout << "Congratulations, you have beaten the final enemy!" << endl; }
    




//     weapon w;
//     Armour a(21, "lmao", "nope", 10,10,10);
//     cout << "Made generic stuff" << endl;
//     activePlayer.setCurrentWeapon(w);
//         cout << "testlol" << activePlayer.getCurrentWeapon().get_paperAtk() << endl;
//         cout << "TEST1" << activePlayer.getCurrentArmour().get_paperDef() << endl;
//     activePlayer.setCurrentArmour(a);
//         cout << "TEST2" << activePlayer.getCurrentArmour().get_paperDef() << endl;
// bool combatLoop = true;

// while (combatLoop == true)
// {
//     cout << "It's your turn!" << endl;
//     cout << "" << endl;
//     cout << "" <<endl;
//     combatSystem.playerAttackType(activePlayer);
//     combatSystem.enemyDefenseType();
//     combatSystem.getDmgMultiplierFromPlayer(activePlayer,e);

//     combatSystem.playerDealtDmg(activePlayer,e);
//     //check if enemy is alive
//     cout << "you have " << activePlayer.get_HP() << "HP" << endl;

//     drawHUD(activePlayer,20);

//     cout << "It's enemy's turn!" << endl;
//     cout << "" << endl;
//     cout << "" <<endl;
//     combatSystem.playerDefense();
//     combatSystem.enemyAttack();
//     combatSystem.getDmgMultiplierFromEnemy();

//     //cout << "you have " << activePlayer.get_HP() << "HP" << endl;
//     drawHUD(activePlayer,20);
//     cout << e.get_name() << " has " << e.get_HP() << "HP remaining" << endl; 
//     //calc dmg
//     //check if player is alive
// }
    return 0;
}