#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>
// #include "Actor.h"
#include "Player.h"

using namespace std;

struct Reward {
    int index;
    string name;
    double value;
};

class RewardSystem {
private:
    vector<Reward> rewards;
    vector<Reward> chosenRewards;  // Keep track of chosen rewards
    vector<int> displayedIndices; //reward 1 - 2 -3
    set<int> displayedIndicesSet;  // Use a set to track displayed indices

    // A function to check if a reward with a specific index has been chosen (Consumable)
    bool hasChosenReward(int index) {
        for (const Reward& reward : chosenRewards) {
            if (reward.index == index) {
                return true;
            }
        }
        return false;
    }

    // Remove a specific reward from the storage
    // void removeReward(int index) {
    //     for (size_t i = 0; i < rewards.size(); ++i) {
    //         if (rewards[i].index == index) {
    //             rewards.erase(rewards.begin() + i);
    //             break;
    //         }
    //     }
    // }

public:
    RewardSystem() {
        // Initialize the storage with 11 different rewards with attributes and indices

        // Base stats
        rewards.push_back({1, "+1 All ATK Type", 1});
        rewards.push_back({2, "+1 All DEF Type", 1});
        rewards.push_back({3, "+2 Rock ATK", 2});
        rewards.push_back({4, "+2 Rock DEF", 2});
        rewards.push_back({5, "+2 Paper DEF", 2});
        rewards.push_back({6, "+2 Paper DEF", 2});
        rewards.push_back({7, "+2 Scissor DEF", 2});
        rewards.push_back({8, "+2 Scissor DEF", 2});
        rewards.push_back({9, "+10 max HP", 10});

        // Consumable
        rewards.push_back({10, "+1 health potion", 0});  // Value
        rewards.push_back({10, "+1 bomb", 1});          // Value
    }

    void displayRandomRewards(Player _player) {

        int selectedRewardIndex;        // The index chosen from the player 
        int randomIndex;            
        // Prompt player to choose reward
        cout << "-----------------------------------" << endl;
        cout << "Choose one of the following rewards:" << endl;

        for (int i = 0; i < 3; ++i) {
            // Generate a random index and ensure it's not a duplicate
            do {
                randomIndex = rand() % rewards.size();
            } while (displayedIndicesSet.find(rewards[randomIndex].index) != displayedIndicesSet.end());

            displayedIndices.push_back(randomIndex);
            displayedIndicesSet.insert(rewards[randomIndex].index);

            cout << i + 1 << ". " << rewards[randomIndex].name << " (Value: " << rewards[randomIndex].value << ")" << endl;
        }

        int validRewardCheck = 0;
        while (validRewardCheck == 0) {
            int choice; //player choice
            cout << "Enter the index of the reward you want here: ";
            cin >> choice;
            if (choice >= 1 && choice <= 3) {
                selectedRewardIndex = displayedIndices[choice - 1]; // the index of the selected reward 
                cout << "You have chosen : " << rewards[selectedRewardIndex].name << " (Value: " << rewards[selectedRewardIndex].value << ")" << endl;
                cout << "-----------------------------------" << endl;
                int rewardIndex = rewards[selectedRewardIndex].index;    // Initial index of the reward
                // Add the chosen reward to the chosenRewards vector
                chosenRewards.push_back(rewards[selectedRewardIndex]);
                validRewardCheck = validRewardCheck + 1;
                switch(rewards[selectedRewardIndex].index) {
                    case 1:
                        _player.set_attack(_player.get_attack() + rewards[selectedRewardIndex].value);
                        cout << "Your current ATK: " << _player.get_attack() << endl;
                        break;
                    case 2:
                        _player.set_defence(_player.get_defence() + rewards[selectedRewardIndex].value);
                        cout << "Your current DEF: "<<_player.get_defence() << endl;
                        break;
                    case 3:
                        _player.Actor::set_rockAtk(_player.get_rockAtk() + rewards[selectedRewardIndex].value);
                        cout << "Your current rockATK: " << _player.get_rockAtk() << endl;
                        break;
                    case 4:
                        _player.Actor::set_rockDef(_player.get_rockDef() + rewards[selectedRewardIndex].value);
                        cout <<  "Your current rockDEF: " << _player.get_rockDef() << endl;
                        break;
                    default:
                        cout << "Hihi" << endl;
                        cout << rewards[selectedRewardIndex].index << endl;
                        break;
                }
    
            } 
            else {
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;

            }
        }
    }
};
