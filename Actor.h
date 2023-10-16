#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
using namespace std;


class Actor
{
protected:
    string name;
    int HP;
    double rockAttack, paperAttack, scissorsAttack;
    double rockDefence, paperDefence, scissorsDefence;

    

public:
    Actor() : Actor("defaultActorName", 100){};
    Actor(string argname, int argHP)
    {
        name = argname;

        HP=argHP;
    
        rockAttack = 0;
        paperAttack = 0;
        scissorsAttack = 0;
        
        rockDefence = 0;
        paperDefence = 0;
        scissorsDefence = 0;

    };

    string get_name()
    {
        return name;
    };
    void set_name(string name)
    {
        name = name;
    };

   

    double get_rockAtk()
    {
        return rockAttack;
    }
    void set_rockAtk(double newRockAtk) // sets rock/paper/scissor atk/def by multiplying base Atk/Def by modifier. Player will have items, and this will be defined in their class
    {
        rockAttack =
            newRockAtk;
    };

    void set_paperAtk(double newPaperAtk)
    {
        paperAttack = newPaperAtk;
    };

    double get_paperAtk()
    {
        return paperAttack;
    }

    void set_scissorsAtk(double newScissorsAtk)
    {
        scissorsAttack = newScissorsAtk;
    };

    double get_scissorsAtk()
    {
        return scissorsAttack;
    }

    void set_rockDef(double newRockDef)
    {
        rockDefence=newRockDef;
    };

    double get_rockDef()
    {
        return rockDefence;
    };

    void set_paperDef(double newPaperDef)
    {
        paperDefence=newPaperDef;
    };

    double get_paperDef()
    {
        return paperDefence;
    };

    void set_scissorsDef(double newScissorDef)
    {
        scissorsDefence=newScissorDef;
    };

    double get_scissorsDef()
    {
        return scissorsDefence;
    };

    int get_HP (){
        return HP;
    }

    void set_HP(int newHP){
        HP= newHP;
    }

    

    ~Actor(){};
};

#endif