#include<iostream>
using namespace std;
#include "string"
#include <fstream>
#include "PlayerUnitTest.h"
#include "saveUnitTest.h"
#include "SaveLoadFunctions.h"

int main(){
    PlayerUnitTest put;
    put.runTests();
    saveUnitTest sut;
    sut.runTests();
    

   

    return 0;
}