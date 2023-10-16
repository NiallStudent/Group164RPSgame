#include<iostream>
using namespace std;
#include "string"
#include <fstream>
#include "PlayerUnitTest.h"
#include "saveUnitTest.h"

int main(){
    PlayerUnitTest put;
    put.runTests();
    Player savePlayer("saveplayer",123,22,11);
     weapon saveWeapon(00,"SaveBlade","save blade description",3,3,3);
     Armour savearmour(123,"SaveArmour","save descripiton",33,44,44);
    saveUnitTest sut;
    sut.runTests(savePlayer,saveWeapon,savearmour);
    

   

    return 0;
}