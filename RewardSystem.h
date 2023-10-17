#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>
// #include "Actor.h"
#include "Consumable.h"
#include "Potion.h"
#include "Bomb.h"
#include "Player.h"

using namespace std;



class RewardSystem {


public:

void newRewards(Player* activePlayer, int currentLevel){
        Bomb* BigBomb = new Bomb();
        Potion* HealthPotion = new Potion();
        bool  isRewardChoiceValid = false;
        while (isRewardChoiceValid == false)
        {
        cout << "Pick a reward: 1 for +" << currentLevel << " base attack, 2 for +" << currentLevel << " base defence, 3 for one bomb or 4 for one health potion" << endl;
            int rewardChoice;
            cin >> rewardChoice;
        switch (rewardChoice)
        {
        case 1:
            
                    activePlayer->set_attack(activePlayer->get_attack()+currentLevel);
                       cout << "Your current base attack is now: " << activePlayer->get_attack() << endl;
                       activePlayer->set_rockAtk();
                       activePlayer->set_paperAtk();
                       activePlayer->set_scissorsAtk();
                       isRewardChoiceValid = true; 

        break;

        case 2:
            
                         activePlayer->set_defence(activePlayer->get_defence()+currentLevel);
                       cout << "Your current base attack is now: " << activePlayer->get_defence() << endl;
                       activePlayer->set_rockDef();
                       activePlayer->set_paperDef();
                       activePlayer->set_scissorsDef();
                       isRewardChoiceValid = true;

        break;
    
        case 3:  
                        
                        activePlayer->addToInventory(BigBomb);
                        isRewardChoiceValid = true;
        break;

        case 4:
                        
                        activePlayer->addToInventory(HealthPotion);
                        isRewardChoiceValid = true;
        break;

        default:
        cout << "Please enter a valid choice" << endl;
        break;
        }
        }

    
}





};
