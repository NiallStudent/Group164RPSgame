#include "Player.h"
using namespace std;
#include <iostream>

class PlayerUnitTest
{
private:

void testHP(Player TestPlayer){
    if (TestPlayer.get_HP()!=100)
    {
        cout<<"ERROR HP get"<<endl;
        cout<<TestPlayer.get_HP()<<endl;
        
    }
    int HPTest = 80;
    TestPlayer.set_HP(HPTest);
    if (TestPlayer.get_HP()!=HPTest)
    {
        cout<<"ERROR HP set"<<endl;
        cout<<TestPlayer.get_HP()<<endl;

    };

    if (TestPlayer.get_name()!="DefaultPlayerName")
    {
        cout<<"Error Name get"<<endl;
        cout<<TestPlayer.get_name()<<endl;
    }
    string newName = "newTestName";
    TestPlayer.set_name(newName);
    if (TestPlayer.get_name()!=newName)
    {
        cout<<"ERROR Name set"<<endl;
        cout<<TestPlayer.get_name();
    }
    
    
    
    
}
    
public:
    void runTests(){
        Player TestPlayer;
        testHP(TestPlayer);
        

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
