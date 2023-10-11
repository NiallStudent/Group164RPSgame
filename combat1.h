#ifndef COMBAT1_H
#define COMBAT1_H

#include "Player.h"
#include "Enemy.h"
class combat {
    private:
        int playerTypeOfAttack;
        int playerTypeOfDefense;
        int enemyTypeOfAttack;
        int enemyTypeOfDefense;
        double damageMultiplier;
    public:
        combat();
        int playerAttack(Player);
        int playerDefense();
        int enemyAttack();
        int enemyDefense(Enemy);
        int getDmgMultiplierFromPlayer(Player, Enemy);
        int getDmgMultiplierFromEnemy();
        void playerDealtDmg(Player,Enemy);
        void enemyDealtDmg();
        int getPlayerCurrentHP();
        int getEnemyCurrentHP();
};
#endif