#include <iostream>
#include "CombatSystem.h"
#include <string>
#include "Player.h"
#include "Enemy.h"
#include <fstream>
#include "SaveLoadFunctions.h"
using namespace std;


int main() {

cout << "~=Welcome to RPS Hero=~" << endl;
int currentLevel = 1; //level system initialiser 

Player activePlayer;//creates the player. This will be replaced by a loaded player or changed at character creation

//Check for save file
SaveLoadFunctions SLFunc;
fstream data_file;
data_file.open("saveFile.txt", ios::in);
if (data_file.is_open())
{
    cout<<"Save data found"<<endl;
    data_file.close();
    activePlayer = SLFunc.LoadPlayer();
     //if save data is not found.
}
else
{
cout<<"saveFile not found. Creating new hero"<<endl;






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
     activePlayer=Player(playerName,100,5,5);                                //initialising classes that will be used during combat loop
   
    /* activePlayer.setCurrentArmour();
    activePlayer.setCurrentWeapon(); */
    }
    weapon baseWeapon(100,"Mundane Club", "Not much to look at",4,3,3);
    Armour baseArmour(101, "Mundane Armour", "Not much to look at",3,3,3);
    weapon sword(102, "Sword of Justice", "It's shiny",5,5,8);
    weapon club(103, "Club of doom", "Slow but painful",10,4,4);
    weapon whip(104, "Whip of pain", "Green and spiky!", 4, 8, 6);
    Armour Plate(105, "Plate Armour", "Cumbersome Plate Armour", 8, 4, 6);
    Armour Cloth(106, "Cloth Armour", "Comfy and easy to wear", 4, 10, 4);
    Armour Chainmail(107, "Chainmail", "Protects from blades", 4, 4, 10);
    combat combatSystem;
    RewardSystem rewards1;
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
               activePlayer.display();
               cout<<"please select an item"<<endl;
               int inventoryIndex;
               cin>>inventoryIndex;
              if (activePlayer.get_item(inventoryIndex)->getName()=="Healing Potion"){
              
                activePlayer.get_item(inventoryIndex)->useItem(&activePlayer);
                activePlayer.removeItem(inventoryIndex);
              }
              else
              {
                activePlayer.get_item(inventoryIndex)->useItem(activeEnemy);
                activePlayer.removeItem(inventoryIndex);
              }
              
              
              
              



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

        if (isAttacking)
        {
        combatSystem.playerAttackType(activePlayer);                        //asks player for attack type
        combatSystem.enemyDefenceType(*activeEnemy);                        //generates random enemy attack
        combatSystem.getDmgMultiplierFromPlayer();                          //determines damange bonus/penalty
        combatSystem.playerDmgDealt(activePlayer, activeEnemy);             //damage calculation and application
        }
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
     if (isDefeated == false)
     {
        cout<<"would you like to save and quit?"<<endl;
        cout<<"(Please enter 1 to save or 2 to continue playing)";
            int saveChoice;
            cin >> saveChoice;
            switch (saveChoice)
            {
            case 1:
               cout<<"Saving game";
               SLFunc.SavePlayer(activePlayer,activePlayer.getCurrentWeapon(),activePlayer.getCurrentArmour());
                cout<<"Exiting game";
                return 0;
                break;
            case 2:


                cout<<"Collect your rewards";
            default:
            cout << "Please enter a valid response";
                break;
            }
     }
     


    switch (currentLevel)                                           //reward system based on number of enemies defeated
     {
    case 1:
    rewards1.newRewards(&activePlayer, currentLevel);
    break;
    case 2:
    rewards1.newRewards(&activePlayer, currentLevel);
    break;
    case 3:
    rewards1.newRewards(&activePlayer, currentLevel);
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
    rewards1.newRewards(&activePlayer, currentLevel);
    break;
    case 6:
    rewards1.newRewards(&activePlayer, currentLevel);
    break;
    case 7:
    rewards1.newRewards(&activePlayer, currentLevel);
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
        rewards1.newRewards(&activePlayer, currentLevel+5);
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
    





    return 0;
}