#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "RewardSystem.h"

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned>(time(nullptr)));

    RewardSystem rewardSystem;

        rewardSystem.displayRandomRewards();


    return 0;
}