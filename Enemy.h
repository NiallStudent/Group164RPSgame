#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;
#include "Actor.h"


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
    this->rockAttack=rAtk;
    this->rockDefence=rDef;
    this->paperAttack=pAtk;
    this->paperDefence=pDef;
    this->scissorsAttack=sAtk;
    this->scissorsDefence=sDef;

    this->rockAtkHint=rockAtkHint;
    this->paperAtkHint=paperAtkHint;
    this->ScissorsAtkHint=scissorsAtkHint;
    this->rockDefHint=rockDefence;
    this->paperDefHint=paperDefence;
    this->scissorsDefence=scissorsDefence;

   }

   //shouldnt need getters or setters if we can access class directly
};

#endif