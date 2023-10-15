#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;
#include "Actor.h"
class Consumable;
class Potion;
class Bomb;


class Enemy: public Actor
{
protected:
    string rockAtkHint,paperAtkHint,ScissorsAtkHint;
    string rockDefHint,paperDefHint,ScissorsDefHint;
    

public:
    Enemy():Enemy("Enemy Name",100,
    10,10,10,10,10,10,
    "rock attack","paper attack","scissor attack",
    "rock defence","paper defence","scissors defence"){}
   Enemy(string argName, int ArgHP, double rAtk, double pAtk, double sAtk,
                                    double rDef, double pDef, double sDef, 
   string rockAtkHint,string paperAtkHint,string scissorsAtkHint,
   string rockDefHint,string paperDefHint,string scissorsDefHint )
   :Actor(argName,ArgHP){
    rockAttack=rAtk;
    rockDefence=rDef;
    paperAttack=pAtk;
    paperDefence=pDef;
    scissorsAttack=sAtk;
    scissorsDefence=sDef;

    rockAtkHint=rockAtkHint;
    paperAtkHint=paperAtkHint;
    ScissorsAtkHint=scissorsAtkHint;
    rockDefHint=rockDefence;
    paperDefHint=paperDefence;
    scissorsDefence=scissorsDefence;

   }

   //shouldnt need getters or setters if we can access class directly
};

#endif