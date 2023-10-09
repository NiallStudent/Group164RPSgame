#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
using namespace std;


class Actor
{
protected:
    string name;
    int HP;
    double Attack, rockAttack, paperAttack, scissorsAttack;
    double Defence, rockDefence, paperDefence, scissorsDefence;

    

public:
    Actor() : Actor("defaultActorName", 100, 20, 20){};
    Actor(string name, int HP, double Attack, double Defence)
    {
        this->name = name;
        this->Attack = Attack;
        this->rockAttack = Attack;
        this->paperAttack = Attack;
        this->scissorsAttack = Attack;
        this->Defence = Defence;
        this->rockDefence = Defence;
        this->paperDefence = Defence;
        this->scissorsDefence = Defence;

    };

    string get_name()
    {
        return this->name;
    };
    void set_name(string name)
    {
        this->name = name;
    };

    double get_attack()
    {
        return this->Attack;
    };

    void set_attack(double Attack)
    {
        this->Attack = Attack;
    };

    double get_rockAtk()
    {
        return this->rockAttack;
    }
    void setRockAtk(double rockMultiplier) // sets rock/paper/scissor atk/def by multiplying base Atk/Def by modifier. Player will have items, and this will be defined in their class
    {
        this->rockAttack =
            this->Attack*rockMultiplier;
    };

    void setPaperAtk(double paperMultiplier)
    {
        this->paperAttack =
            this->Attack*paperMultiplier;
    };

    double get_PaperAtk()
    {
        return this->paperAttack;
    }

    void setScissorsAtk(double scissorMultiplier)
    {
        this->rockAttack =
            this->Attack*scissorMultiplier;
    };

    double get_ScissorsAtk()
    {
        return this->scissorsAttack;
    }

    void setRockDef(double rockDefence)
    {
        this->rockDefence = this->Defence*rockDefence;
    };

    double get_rockDef()
    {
        return this->rockDefence;
    };

    void setPaperDef(double paperDefence)
    {
        this->paperDefence = this->Defence *paperDefence;
    };

    double get_paperDef()
    {
        return this->paperDefence;
    };

    void setScissorsDef(double scissorDefence)
    {
        this->scissorsDefence = this->Defence*scissorDefence;
    };

    double get_scissorsDef()
    {
        return this->scissorsDefence;
    };

    int getHP (){
        return this->HP;
    }

    void setHP(int newHP){
        this->HP= newHP;
    }

    

    ~Actor(){};
};

#endif