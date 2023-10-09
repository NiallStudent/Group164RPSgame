#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
using namespace std;
#include "Actor.h"


class Enemy: public Actor
{
protected:
    string threat;
    

public:
   Enemy(string argName, int ArgHP, double argAtk, double argDef, string argThreat):Actor(argName,ArgHP,argAtk,argDef){
    this->threat=argThreat;
   }

#endif