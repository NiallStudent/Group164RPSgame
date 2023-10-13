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
    vector<Reward> chosenRewards;  // Keep track of chosen rewards

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
    void removeReward(int index) {
        for (size_t i = 0; i < rewards.size(); ++i) {
            if (rewards[i].index == index) {
                rewards.erase(rewards.begin() + i);
                break;
            }
        }
    }

public:
    RewardSystem() {
        // Initialize the storage with 11 different rewards with attributes and indices

        // Base stats
        rewards.push_back({1, "+6 All ATK Type", 6});
        rewards.push_back({2, "+6 All DEF Type", 6});
        rewards.push_back({3, "+10 Rock ATK", 10});
        rewards.push_back({4, "+10 Rock DEF", 10});
        rewards.push_back({5, "+10 Paper DEF", 10});
        rewards.push_back({6, "+10 Paper DEF", 10});
        rewards.push_back({7, "+10 Scissor DEF", 10});
        rewards.push_back({8, "+10 Scissor DEF", 10});

        // Consumable
        rewards.push_back({9, "+1 health potion", 0});  // Value
        rewards.push_back({9, "+1 bomb", 0});          // Value
    }

    void displayRandomRewards() {

        // Prompt player to choose reward
        cout << "-----------------------------------" << endl;
        cout << "Choose one of the following rewards:" << endl;
        vector<int> displayedIndices; //reward 1 - 2 -3
        set<int> displayedIndicesSet;  // Use a set to track displayed indices

        for (int i = 0; i < 3; ++i) {
            int randomIndex;

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
            int selectedRewardIndex = displayedIndices[choice - 1]; // the index of the selected reward 
            cout << "You have chosen: " << rewards[selectedRewardIndex].name << " (Value: " << rewards[selectedRewardIndex].value << ")" << endl;
            cout << "-----------------------------------" << endl;

            // Add the chosen reward to the chosenRewards vector
            chosenRewards.push_back(rewards[selectedRewardIndex]);
            validRewardCheck++;
            // Remove the chosen reward from the storage
            if (rewards[selectedRewardIndex].index == 5) {
                // inventory.push_back(rewards[selectedRewardIndex]);
            }

        } else {
            cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
        }
    }
};
