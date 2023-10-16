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

// struct Reward {
//     int index;
//     string name;
//     double value;
// };

class RewardSystem {
// private:
//     vector<Reward> rewards;
//     vector<Reward> chosenRewards;  // Keep track of chosen rewards
//     vector<int> displayedIndices; //reward 1 - 2 - 3
//     set<int> displayedIndicesSet;  // Use a set to track displayed indices

//     // A function to check if a reward with a specific index has been chosen (Consumable)
//     bool hasChosenReward(int index) {
//         for (const Reward& reward : chosenRewards) {
//             if (reward.index == index) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     // Remove a specific reward from the storage
//     // void removeReward(int index) {
//     //     for (size_t i = 0; i < rewards.size(); ++i) {
//     //         if (rewards[i].index == index) {
//     //             rewards.erase(rewards.begin() + i);
//     //             break;
//     //         }
//     //     }
//     // }

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
//     void generateRewards(int multiplier) {
//         // Initialize the storage with 11 different rewards with attributes and indices

//         // Base stats
//         double baseChange = 1 * multiplier;
//         double statchange = 2 * multiplier;
//         double increaseHP = 25 * multiplier;
//         rewards.push_back({1, "+ All ATK Type", baseChange});
//         rewards.push_back({2, "+ All DEF Type", baseChange});
//         rewards.push_back({3, "+Rock ATK", statchange});
//         rewards.push_back({4, "+Rock DEF", statchange});
//         rewards.push_back({5, "+Paper ATK", statchange});
//         rewards.push_back({6, "+Paper DEF", statchange});
//         rewards.push_back({7, "+Scissor ATK", statchange});
//         rewards.push_back({8, "+Scissor DEF", statchange});
//         rewards.push_back({9, "+Heal some HP", increaseHP});

//         // Consumable
//         rewards.push_back({10, "+1 health potion", 0});  // Value
//         rewards.push_back({10, "+1 bomb", 1});           // Value
//     }

//     void displayRandomRewards(Player* _player) {

//         int selectedRewardIndex;        // The index chosen from the player 
//         int randomIndex;            
//         // Prompt player to choose reward
//         cout << "-----------------------------------" << endl;
//         cout << "Choose one of the following rewards:" << endl;

//         for (int i = 0; i < 3; ++i) {
//             // Generate a random index and ensure it's not a duplicate
//             do {
//                 randomIndex = rand() % rewards.size();
//             } while (displayedIndicesSet.find(rewards[randomIndex].index) != displayedIndicesSet.end());

//             displayedIndices.push_back(randomIndex);
//             displayedIndicesSet.insert(rewards[randomIndex].index);

//             cout << i + 1 << ". " << rewards[randomIndex].name << " (Value: " << rewards[randomIndex].value << ")" << endl;
//         }

//         int validRewardCheck = 0;
//         while (validRewardCheck == 0) {
//             int choice; //player choice
//             cout << "Enter the index of the reward you want here: ";
//             cin >> choice;
//             if (choice >= 1 && choice <= 3) {
//                 selectedRewardIndex = displayedIndices[choice - 1]; // the index of the selected reward 
//                 cout << "You have chosen : " << rewards[selectedRewardIndex].name << " (Value: " << rewards[selectedRewardIndex].value << ")" << endl;
//                 cout << "-----------------------------------" << endl;
//                 int rewardIndex = rewards[selectedRewardIndex].index;    // Initial index of the reward
//                 // Add the chosen reward to the chosenRewards vector
//                 chosenRewards.push_back(rewards[selectedRewardIndex]);
//                 validRewardCheck = validRewardCheck + 1;
//                 switch(rewards[selectedRewardIndex].index) {
//                     case 1: 
//                        _player->set_attack(_player->get_attack()+1);
//                        cout << "Your current base attack: " << _player->get_attack() << endl;
//                        _player->set_rockAtk();
//                        _player->set_paperAtk();
//                        _player->set_scissorsAtk();
//                         break;
//                     case 2:
//                        _player->set_defence(_player->get_defence()+1);
//                        cout << "Your current base defence: " << _player->get_defence() << endl;
//                        _player->set_rockDef();
//                        _player->set_paperDef();
//                        _player->set_scissorsDef();
//                         break;
//                     case 3:
//                         _player->set_rockAtk(3);
//                         cout << "Your current rockATK: " << _player->get_rockAtk() << endl;
//                         break;
//                     case 4:
//                         _player->set_rockDef(3);
//                         cout <<  "Your current rockDEF: " << _player->get_rockDef() << endl;
//                         break;
//                     case 5:
//                         _player->set_paperAtk(3);
//                         cout <<  "Your current paperATK: " << _player->get_paperAtk() << endl;
//                         break;
//                     case 6:
//                         _player->set_paperDef(3);
//                         cout <<  "Your current paperDEF: " << _player->get_paperDef() << endl;
//                         break;
//                     case 7:
//                         _player->set_scissorsAtk(3);
//                         cout <<  "Your current scissorsATK: " << _player->get_paperAtk() << endl;
//                         break;
//                     case 8:
//                         _player->set_scissorsDef(3);
//                         cout <<  "Your current scissorsDEF: " << _player->get_scissorsDef() << endl;
//                         break;
//                     case 9:
//                         _player->set_HP(_player->get_HP() + rewards[selectedRewardIndex].value);
//                         break;
//                     case 10:
                        
//                         if (rewards[selectedRewardIndex].value==0){
//                         Potion* Healthpotion = new Potion();
//                         _player->addToInventory(Healthpotion);
//                         }
//                         else if (rewards[selectedRewardIndex].value==1){
//                             Bomb* BigBomb = new Bomb();
//                         _player->addToInventory(BigBomb);
//                         }

                    

//                         break;
                        
//                         default:
//                         cout << "Something went wrong, oops" << endl;
//                         cout << rewards[selectedRewardIndex].index << endl;
//                         break;
//                 }
    
//             } 
//             else {
//                 cout << "Invalid choice. Please enter a number between 1 and 3." << endl;

//             }
//         }
//     }
// }
