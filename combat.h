#ifndef COMBAT_H
#define COMBAT_H
#include "Actor.h"
#include "RewardSystem.h"

class combat {
    private:
        int playerTypeOfAttack;
        int playerTypeOfDefense;
        int enemyTypeOfAttack;
        int enemyTypeOfDefense;
        int damageMultiplier;

    public:
        combat();
        int playerAttack();
        int playerDefense();
        int enemyAttack();
        int enemyDefense();
        int getDmgMultiplierFromPlayer();
        int getDmgMultiplierFromEnemy();
        void playerDealtDmg();
        void enemyDealtDmg();
        int getPlayerCurrentHP();
        int getEnemyCurrentHP();
        void checkWin(RewardSystem _rewardSystem);
        void checkLose(Actor _player);
};
#endif