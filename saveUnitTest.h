#ifndef SAVEUNITTEST_H
#define SAVEUNITTEST_H

#include<iostream>
using namespace std;
#include "string"
#include <fstream>
#include "Player.h"

class saveUnitTest
{
private:

void loadSaveTest(){
    //Write data for Player, weapon and armour into txt file
     Player savePlayer("saveplayer",123,22,11);
     weapon saveWeapon(00,"SaveBlade","save blade description",3,3,3);
     Armour savearmour(123,"SaveArmour","save descripiton",33,44,44);
    fstream data_file;
    data_file.open("saveFile.txt", ios::out);
    if (data_file.is_open()) {        
        data_file << savePlayer.get_name()<<"\n";
        data_file << savePlayer.get_HP()<<"\n";
        data_file << savePlayer.get_attack()<<"\n";
        data_file << savePlayer.get_defence()<<"\n";
        data_file<<saveWeapon.getID()<<"\n";
        data_file<<saveWeapon.getName()<<"\n";
        data_file<<saveWeapon.getDescription()<<"\n";
        data_file<<saveWeapon.get_rockAtk()<<"\n";
        data_file<<saveWeapon.get_paperAtk()<<"\n";
        data_file<<saveWeapon.get_scissorsAtk()<<"\n";
        data_file<<savearmour.getID()<<"\n";
        data_file<<savearmour.getName()<<"\n";
        data_file<<savearmour.getDescription()<<"\n";
        data_file<<savearmour.get_rockDef()<<"\n";
        data_file<<savearmour.get_paperDef()<<"\n";
        data_file<<savearmour.get_scissorsDef()<<"\n";
        ;
        data_file.close();
    }
    Player loadPlayer("WrongName",200,23,99);
    weapon blankWeapon(111,"blank wep","blank wep desk",22,22,22);
    string weaponName, WeaponDesc;
    int WeaponID;
    double WeaponRAtk, WeaponPAtk, WeaponSAtk;
    Armour loadArmour;
    string armourName, ArmourDesc;
    int ArmourID;
    double ArmourRDef, ArmourPDef, ArmourSDef;
     string data;
    data_file.open("saveFile.txt", ios::in);
    if (data_file.is_open()) {
        string data;
        int i =0;
        while (getline(data_file, data)) {
            switch (i)
            {
            case 0:
                loadPlayer.set_name(data);
                break;

            case 1:
                loadPlayer.set_HP(stoi(data));
                break;

            case 2:
                loadPlayer.set_attack(stod(data));
                break;

            case 3:
                loadPlayer.set_defence(stod(data));
                break;
            //Write current weapon attributes
            case 4:
                WeaponID=stoi(data);
                break;

            case 5:
                weaponName=data;
                break;
            case 6:
                WeaponDesc=data;
                break;
            case 7:
                WeaponRAtk=stod(data);
                break;

            case 8:
                WeaponPAtk=stod(data);
                break;
            
            case 9:
                WeaponSAtk=stod(data);
                break;
                            
        
            
            case 10:
                ArmourID=stoi(data);
                break;

            case 11:
                armourName=data;
                break;
            case 12:
                ArmourDesc=data;
                break;
            case 13:
                ArmourRDef=stod(data);
                break;

            case 14:
                ArmourPDef=stod(data);
                break;
            
            case 15:
                ArmourSDef=stod(data);
                break;
                            
            default:
                break;
              
            }
              i++;
            
            
        }
        data_file.close();
        cout<<loadPlayer.get_name()<<endl;
        cout<<loadPlayer.get_HP()<<endl;
        cout<<loadPlayer.get_attack()<<endl;
        cout<<loadPlayer.get_defence()<<endl;
        //print loaded weapon data
        weapon loadsword(WeaponID,weaponName,WeaponDesc,WeaponRAtk,WeaponPAtk,WeaponSAtk);
        cout<<loadsword.getName();
        //print loaded armour
        Armour loadplate(ArmourID,armourName,ArmourDesc,ArmourRDef,ArmourPDef,ArmourSDef);
        cout<<loadplate.getName();
    } 
}
    
public:
void runTests(){
    loadSaveTest();
}
    saveUnitTest(/* args */);
    ~saveUnitTest();
};

saveUnitTest::saveUnitTest(/* args */)
{
}

saveUnitTest::~saveUnitTest()
{
}


#endif
