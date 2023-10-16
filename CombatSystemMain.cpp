#include <iostream>
#include "CombatSystem.h"
#include "Actor.h"
#include <string>
#include "Player.h"

using namespace std;

int main() {


    srand(time(NULL));          // use to make random numbers

    // Create a player object and enemy and reward object.
    Player _player("Tommy", 100, 20, 20);
    Enemy _enemy("Grizzly Bear", 200, 5, 5, 10, 5, 10, 10,
    "It looks like it's about to charge headfirst",
    "It opens its arms wide and advances",
    "It readies its claws and rushes at you on its hind legs",
    "It looks ready to meet your next attack with its thick skull",
    "It opens its arms wide and waits for your next move",
    "It takes a defensive stance and readies its claws"
    );
    RewardSystem _reward;

    // Create a combat object.
    combat Test;

    // Perform the player's attack.

        Test.playerAttackType(_player);
        Test.enemyDefenceType(_enemy);
        Test.getDmgMultiplierFromPlayer();
        Test.playerDmgDealt(_player);
        Test.enemyHPCalc(_enemy);
        _reward.displayRandomRewards(_player);

    // Perform the player's defece.
    Test.playerDefenceType(_player);
    Test.enemyAttackType(_enemy);
    Test.getDmgMultiplierFromEnemy();
    Test.playerDmgTaken(_enemy);
    Test.playerHPCalc(_player);


    return 0; // Return 0 to indicate a successful program execution.
}