#ifndef SAVELOADFUNCTION_H
#define SAVELOADFUNCTION_H

#include <iostream>
using namespace std;
#include "Player.h"
#include "Weapon.h"
#include "Armour.h"
#include <fstream>
class SaveLoadFunctions
{
private:
    /* data */
public:
    SaveLoadFunctions(/* args */);
    ~SaveLoadFunctions();

    Player LoadPlayer(){
    fstream data_file;
    //create a blank player to rewrite
    Player loadPlayer("WrongName",200,23,99);
    //stores the values to make the equipment that are stored in the text file
string weaponName, WeaponDesc;
    int WeaponID;
    double WeaponRAtk, WeaponPAtk, WeaponSAtk;
    Armour loadArmour;
    string armourName, ArmourDesc;
    int ArmourID;
    double ArmourRDef, ArmourPDef, ArmourSDef;
     string data;
     //opens text file, then saves data to make the objects in the above variables.
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
                            
            //armour attributes.
            
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
        //cout<<loadPlayer.get_name()<<endl;
        //cout<<loadPlayer.get_HP()<<endl;
        //cout<<loadPlayer.get_attack()<<endl;
        //cout<<loadPlayer.get_defence()<<endl;
        //print loaded weapon data
        weapon loadsword(WeaponID,weaponName,WeaponDesc,WeaponRAtk,WeaponPAtk,WeaponSAtk);
        //cout<<loadsword.getName();
        //print loaded armour
        Armour loadplate(ArmourID,armourName,ArmourDesc,ArmourRDef,ArmourPDef,ArmourSDef);
        //cout<<loadplate.getName();
        cout<<"player loaded successfully\n";
        return loadPlayer;
        
    } 
    return loadPlayer;
}

void SavePlayer(Player SavePlayer, weapon SaveWeapon, Armour SaveArmour){
     fstream data_file;
    data_file.open("saveFile.txt", ios::out);
    if (data_file.is_open()) {        
        data_file << SavePlayer.get_name()<<"\n";
        data_file << SavePlayer.get_HP()<<"\n";
        data_file << SavePlayer.get_attack()<<"\n";
        data_file << SavePlayer.get_defence()<<"\n";
        data_file<<SaveWeapon.getID()<<"\n";
        data_file<<SaveWeapon.getName()<<"\n";
        data_file<<SaveWeapon.getDescription()<<"\n";
        data_file<<SaveWeapon.get_rockAtk()<<"\n";
        data_file<<SaveWeapon.get_paperAtk()<<"\n";
        data_file<<SaveWeapon.get_scissorsAtk()<<"\n";
        data_file<<SaveArmour.getID()<<"\n";
        data_file<<SaveArmour.getName()<<"\n";
        data_file<<SaveArmour.getDescription()<<"\n";
        data_file<<SaveArmour.get_rockDef()<<"\n";
        data_file<<SaveArmour.get_paperDef()<<"\n";
        data_file<<SaveArmour.get_scissorsDef()<<"\n";
        ;
        data_file.close();
    }
}
};

SaveLoadFunctions::SaveLoadFunctions(/* args */)
{
}

SaveLoadFunctions::~SaveLoadFunctions()
{
}





#endif