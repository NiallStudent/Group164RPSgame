#ifndef COMBAT1_H
#define COMBAT1_H

class combat {
    private:
        int playerTypeOfAttack;
        int playerTypeOfDefense;
        int enemyTypeOfAttack;
        int enemyTypeOfDefense;
        int damageMultiplier;
        int rewards;
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
        int chooseRewards();
        void checkWin();
        void checkLose();
};
#endif