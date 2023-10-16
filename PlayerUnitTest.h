#ifndef PLAYERUNITTEST_H
#define PLAYERUNITTEST_H

#include "Player.h"
#include "Enemy.h"
using namespace std;
#include <iostream>
#include "Item.h"

//to run this, compile combat1.cpp and potionTest.cpp

#include "Potion.h" //predeclared potion and consumable class in player to avoid circular dependency
#include "Bomb.h"

class PlayerUnitTest
{
private:

void testPlayerGettersAndSetters(Player TestPlayer){

    //test HP getting and setting. Gaining and losing HP
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

    HPTest=120;
    TestPlayer.set_HP(HPTest);
    if (TestPlayer.get_HP()!=HPTest)
    {
        cout<<"ERROR HP set"<<endl;
        cout<<TestPlayer.get_HP()<<endl;

    };



//Test name getting and setting.
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

//Test base Atk/Def getters and setters.

    if (TestPlayer.get_attack()!=20)
    {
        cout<<"ERROR Attack get"<<endl;
        cout<<TestPlayer.get_attack();
    }
    int newAtk =10;
    TestPlayer.set_attack(newAtk);
    if (TestPlayer.get_attack()!=newAtk)
    {
        cout<<"ERROR set attack"<<endl;
        cout<<TestPlayer.get_attack();
    }

    if (TestPlayer.get_defense()!=20)
    {
        cout<<"ERROR Defence get"<<endl;
        cout<<TestPlayer.get_defense();
    }
    int newDef =15;
    TestPlayer.set_defence(newDef);
    if (TestPlayer.get_defense()!=newDef)
    {
        cout<<"ERROR set def"<<endl;
        cout<<TestPlayer.get_defense();
    }

    cout<<"reached end of player getter and setter tests"<<endl;   
}

void testPlayerEquipmentAndRPS(Player TestPlayer){
    //check default armour and weapon is equipped properly when player is made
    if (TestPlayer.getCurrentWeapon().getName()!="DefaultWeapon")
    {
        cout<<"ERROR Default Weapon name\n";
        cout<<TestPlayer.getCurrentWeapon().getName()<<endl;
    }

    if (TestPlayer.getCurrentArmour().getName()!="defaultArmour")
    {
        cout<<"ERROR Default armour name\n";
        cout<<TestPlayer.getCurrentArmour().getName()<<endl;
    }
    

//Test that RPS atk, def values have been set correctly for default armour.

if (TestPlayer.get_rockAtk()!=40)
{
    cout<<"ERROR rock atk DefaultWeapon\n";
    cout<<TestPlayer.get_rockAtk()<<endl;
}

if(TestPlayer.get_rockDef()!=40){
    cout<<"ERROR Rock def DefaultArmour\n";
    cout<<TestPlayer.get_rockDef()<<endl;
}



//Test equiping new weapons and armour (Not default armour and weapon)

weapon betterWeapon(203,"BetterWeapon","BetterWeaponDescription",5,5,5);
Armour betterArmour(333,"BEtterArmour","BetterArmourDescription",5,5,5);

TestPlayer.setCurrentWeapon(betterWeapon);

if (TestPlayer.getCurrentWeapon().getName()!="BetterWeapon")
{
    cout<<"ERROR NewWeapon name get\n";
    cout<<TestPlayer.getCurrentWeapon().getName()<<endl;
}

if (TestPlayer.get_paperAtk()!=100)
{
    cout<<"ERROR new weaponATK\n";
    cout<<TestPlayer.get_paperAtk()<<endl;

}

TestPlayer.setCurrentArmour(betterArmour);

if(TestPlayer.getCurrentArmour().getName()!="BEtterArmour"){
    cout<<"ERROR New armour name\n";
    cout<<TestPlayer.getCurrentArmour().getName();
}

if(TestPlayer.get_paperDef()!=100){
    cout<<"ERROR newarmour paper def\n";
    cout<<TestPlayer.get_paperDef();
    }

cout<<"End of equipment tests\n";
}

void testPlayerInventory(Player* TestPlayer){
        Potion* pot = new Potion();
    Bomb* bob= new Bomb();
    Enemy* en= new Enemy();
    cout<<"Player HP: "<<TestPlayer->get_HP()<<endl;
    cout<<"Enemy HP: "<<en->get_HP()<<endl;
    cout<<endl;

    /* cout<<TestPlayer->get_HP()<<": Current HP\n";
    pot.useItem(TestPlayer);
    cout<<TestPlayer->get_HP()<<" player has this much hp now\n";
    cout<<"\n\n\n";
    cout<<pot.getDescription()<<endl<<pot.getName(); */

   
    

   cout<<"displaying inventory"<<endl;
    TestPlayer->display();
    TestPlayer->addToInventory(pot);
    TestPlayer->addToInventory(bob);
    TestPlayer->getSizeofInv();
    cout<<"displaying inventory"<<endl;
    TestPlayer->display();
    cout<<endl;
    cout<<TestPlayer->get_item(0)->getDescription()<<endl;
    TestPlayer->get_item(0)->useItem(TestPlayer);
    TestPlayer->removeItem(0);
    cout<<"removed an item"<<endl;
    cout<<endl;
    cout<<TestPlayer->get_item(1)->getDescription()<<endl;
    TestPlayer->get_item(1)->useItem(en);
    TestPlayer->removeItem(1);
    cout<<"removed an item"<<endl;
    
    cout<<endl<<endl;
    
    cout<<TestPlayer->get_HP()<<" player hp";
    cout<<endl;
    cout<<"enemy hp "<<en->get_HP()<<endl;
    TestPlayer->getSizeofInv();
    cout<<"hello\n";
   /*  delete en; */
     /*delete pot;
    delete bob; */
    //delete TestPlayer;
   
   
};





    
public:
    void runTests(){
        Player TestPlayer;
        testPlayerGettersAndSetters(TestPlayer);
        testPlayerEquipmentAndRPS(TestPlayer);
        Player* TestPlayerptr = new Player();
        //testPlayerInventory(TestPlayerptr);
        //cout<<"back to test";
        delete TestPlayerptr;  //something is hanging around after leaving inventory test. Causes segmenation fault
        //return TestPlayerptr;

        
        
        

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

#endif
