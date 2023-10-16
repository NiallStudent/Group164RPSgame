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
     Player savePlayer("saveplayer",123,22,11);
    fstream data_file;
    data_file.open("saveFile.txt", ios::out);
    if (data_file.is_open()) {        
        data_file << savePlayer.get_name()<<"\n";
        data_file << savePlayer.get_HP()<<"\n";
        data_file << savePlayer.get_attack()<<"\n";
        data_file << savePlayer.get_defense()<<"\n";
        data_file.close();
    }
    Player loadPlayer("WrongName",200,23,99);
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
            
            default:
                break;
              
            }
              i++;
            
            
        }
        data_file.close();
        cout<<loadPlayer.get_name()<<endl;
        cout<<loadPlayer.get_HP()<<endl;
        cout<<loadPlayer.get_attack()<<endl;
        cout<<loadPlayer.get_defense()<<endl;
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
