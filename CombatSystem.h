#ifndef COMBAT_H
#define COMBAT_H
#include "Actor.h"
#include "Player.h"
#include "Enemy.h"
#include "RewardSystem.h"
#include <string>
using namespace std;

class combat {
    private:
        int playerTypeOfAttack;         // Player chosen atk type
        int playerTypeOfDefence;        // Player chosen def type
        int enemyTypeOfAttack;          // Enemy chosen atk type
        int enemyTypeOfDefence;         // Enemy chosen def type
        double damageMultiplier;        // Damage multiplier base on this.atk and that.def
        int ATKValue;                   // Atk value of the atk type chosen by player
        int DEFValue;                   // Def value of the def type chosen by player
        double DMGDealt;                // DMG Dealt by player
        double DMGTaken;                // DMG Taken by player
        double playerHP;
        double enemyHP;
    public:
        combat();
        void playerAttackType(Player _player);          // Get atk type from player
        void playerDefenceType(Player _player);         // Get def type from player
        void enemyAttackType(Enemy _enemy);             // Choose atk type for enemy
        void enemyDefenceType(Enemy _enemy);            // Choose def type for enemy
        double getDmgMultiplierFromPlayer();            // Get dmg multiplier base on player atk type and enemy def type
        double getDmgMultiplierFromEnemy();             // Get dmg multiplier base on player def type and enemy atk type
        void playerDmgDealt(Player _player);            // Calc Dmg dealt by player
        void playerDmgTaken(Enemy _enemy);              // Calc Dmg taken by player
        void playerHPCalc(Player _player);              // Calc player's HP after combat
        void enemyHPCalc(Enemy _enemy);                 // Calc enemy's HP after combat
        bool checkWin(RewardSystem _reward);            // Give reward to player if they won the combat
        void checkLose();                               // Check if player lost the combat
};
#endif