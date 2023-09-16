#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player
{
private:
    
    string name;
    int HP;
    double Attack, rockAttack, paperAttack, scissorsAttack;
    double Defence, rockDefence, paperDefence, scissorsDefence;
    int gold;
    
public:
    Player(): Player("defaultName", 100,20,20){};
    Player(string name, int HP, double Attack, double Defence){
        this->name=name;
        this->Attack=Attack;
        this->rockAttack=Attack; this->paperAttack=Attack; this->scissorsAttack=Attack;
        this->Defence=Defence;
        this->rockDefence=Defence; this->paperDefence=Defence; this->scissorsDefence=Defence;

        this->gold=0;
         };

        string get_name(){
            return this->name;
        };
        void set_name(string name){
            this->name=name;
        }

        double get_attack(){
            return this->Attack;
        };
        void set_name(double Attack){
            this->Attack=Attack;
        }

        
   
    ~Player();
};



#endif