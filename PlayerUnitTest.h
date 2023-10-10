#include "Player.h"
using namespace std;
#include <iostream>

class PlayerUnitTest
{
private:

void testHP(Player p){
    if (p.get_HP()!=100)
    {
        cout<<"ERROR HP get"<<endl;
        cout<<p.get_HP()<<endl;
        
    }
    int HPTest = 80;
    p.set_HP(HPTest);
    if (p.get_HP()!=80)
    {
        cout<<"ERROR HP set"<<endl;

    };
    
    
    
}
    
public:
    void runTests(){
        Player p("unit test player",100,20,20);
        cout<<p.get_HP()<<endl;
        Actor a("new actor",80);
        cout<<a.get_HP();
        testHP(p);
        

    }

    PlayerUnitTest(/* args */);
    ~PlayerUnitTest();
};

PlayerUnitTest::PlayerUnitTest(/* args */)
{
}

PlayerUnitTest::~PlayerUnitTest()
{
}
