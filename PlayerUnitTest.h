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
    if (p.get_HP()!=HPTest)
    {
        cout<<"ERROR HP set"<<endl;
        cout<<p.get_HP()<<endl;

    };

    if (p.get_name()!="DefaultPlayerName")
    {
        cout<<"Error Name get"<<endl;
        cout<<p.get_name()<<endl;
    }
    string newName = "newTestName";
    p.set_name(newName);
    if (p.get_name()!=newName)
    {
        cout<<"ERROR Name set"<<endl;
        cout<<p.get_name();
    }
    
    
    
    
}
    
public:
    void runTests(){
        Player p;
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
