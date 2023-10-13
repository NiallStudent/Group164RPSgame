#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

struct Reward {
    int index;
    string name;
    double value;
};

class RewardSystem {
private:
    vector<Reward> rewards;
    // // A function to check if a reward with a specific index has been chosen (Equipment)
    // bool hasChosenReward(int index) {
    //     for (const Reward& reward : chosenRewards) {
    //         if (reward.index == index) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    // // Remove a specific reward from the storage
    // void removeReward(int index) {
    //     for (size_t i = 0; i < rewards.size(); ++i) {
    //         if (rewards[i].index == index) {
    //             rewards.erase(rewards.begin() + i);
    //             break;
    //         }
    //     }
    // }

    vector<Reward> chosenRewards;  // Keep track of chosen rewards
public:
    RewardSystem() {
        // Initialize the storage with 15 different rewards with attributes and indices

        // // Equipments
        // rewards.push_back({1, "Drago Vest", 10});
        // // Rock weapon
        // rewards.push_back({8, "Club", 1.5});
        // // Scissors weapon
        // rewards.push_back({2, "Demon Sword", 1.5});
        
        // Base stats
        rewards.push_back({3, "+10 base ATK", 10});
        rewards.push_back({4, "+10 base DEF", 10});

        // Stat boost
        rewards.push_back({5, "+ 5%ATK", 5});
        rewards.push_back({6, "+ 5%DEF", 5});

        // Consumable
        rewards.push_back({7, "1 health potion"});
        rewards.push_back({7, "1 bomb"});

    }

    virtual void displayRandomRewards() {

        // Prompt player to choose reward
        cout << "Choose one of the following rewards:" << endl;
        vector<int> displayedIndices;
        set<int> displayedIndicesSet;  // Use a set to track displayed indices

        for (int i = 0; i < 3; ++i) {
            int randomIndex;

            // Generate a random index and ensure it's not a duplicate or a previously chosen index
            do {
                randomIndex = rand() % rewards.size();
            } while (displayedIndicesSet.find(rewards[randomIndex].index) != displayedIndicesSet.end() ||
                     (rewards[randomIndex].index == 2 && hasChosenReward(2)));

            displayedIndices.push_back(randomIndex);
            displayedIndicesSet.insert(rewards[randomIndex].index);

            cout << i + 1 << ". " << rewards[randomIndex].name << " (Value: " << rewards[randomIndex].value << ")" << endl;
        }

        int choice;
        cout << "Enter the index of the reward you want here: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) {
            int selectedRewardIndex = displayedIndices[choice - 1];
            cout << "You have chosen: " << rewards[selectedRewardIndex].name << " (Value: " << rewards[selectedRewardIndex].value << ")" << endl;

            // Remove the chosen reward from the storage
            if (rewards[selectedRewardIndex].index == 1) {
                removeReward(1);
            }
            if (rewards[selectedRewardIndex].index == 2) {
                removeReward(2);
            }


        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    }
};