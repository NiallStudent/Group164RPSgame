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
    Actor(string name, int HP)
    {
        this->name = name;
    
        this->rockAttack = 0;
        this->paperAttack = 0;
        this->scissorsAttack = 0;
        
        this->rockDefence = 0;
        this->paperDefence = 0;
        this->scissorsDefence = 0;

    };

    string get_name()
    {
        return this->name;
    };
    void set_name(string name)
    {
        this->name = name;
    };

   

    double get_rockAtk()
    {
        return this->rockAttack;
    }
    void setRockAtk(double newRockAtk) // sets rock/paper/scissor atk/def by multiplying base Atk/Def by modifier. Player will have items, and this will be defined in their class
    {
        this->rockAttack =
            newRockAtk;
    };

    void setPaperAtk(double newPaperAtk)
    {
        this->paperAttack =
            newPaperAtk;
    };

    double get_PaperAtk()
    {
        return this->paperAttack;
    }

    void setScissorsAtk(double newScissorsAtk)
    {
        this->scissorsAttack =
            newScissorsAtk;
    };

    double get_ScissorsAtk()
    {
        return this->scissorsAttack;
    }

    void setRockDef(double newRockDef)
    {
        this->rockDefence=newRockDef;
    };

    double get_rockDef()
    {
        return this->rockDefence;
    };

    void setPaperDef(double newPaperDef)
    {
        this->paperDefence=newPaperDef;
    };

    double get_paperDef()
    {
        return this->paperDefence;
    };

    void setScissorsDef(double newScissorDef)
    {
        this->scissorsDefence=newScissorDef;
    };

    double get_scissorsDef()
    {
        return this->scissorsDefence;
    };

    int get_HP (){
        return this->HP;
    }

    void set_HP(int newHP){
        this->HP= newHP;
    }

    

    ~Actor(){};
};

#endif