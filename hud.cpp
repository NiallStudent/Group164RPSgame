#include <iostream>
#include "Weapon.h"
#include "Armour.h"
#include "Player.h"
using namespace std;

// int main(){
// int currentLevel = 1000;

// string TestPlayerName;                                  //creating the character name, checking length is between 1 and 16 characters long
// bool nameLengthCheck = false;
// while (nameLengthCheck == false){                   //loops until there is a valid name
// cout << "enter your name ( minimum 1, maximum 16 characters)" << endl;
// cin >> TestPlayerName;
// if (TestPlayerName.size() < 17 && TestPlayerName.size() > 0)
//     {
//     nameLengthCheck = true;
//     }
// else {
//     cout << "Please enter a valid name" << endl;
//     }
// }

// TestPlayer TestPlayer(TestPlayerName, 100, 10, 10);

void drawHUD(Player TestPlayer, int currentLevel){

int hudNameSpacer = 26 - TestPlayer.get_name().size();
int hudWpnSpacer = 20 - TestPlayer.getCurrentWeapon().getName().size();
int hudAmrSpacer = 20 - TestPlayer.getCurrentArmour().getName().size();
int rAtkInt = TestPlayer.getCurrentWeapon().get_rockAtk();          //voodoo to make the spacing in the HUD work nicely later
string rAtk = to_string(rAtkInt);                                   //convert double to int, then to string to get value length
int pAtkInt = TestPlayer.getCurrentWeapon().get_paperAtk();         //so that can be used to determine spacing shouldn't break until very high values.
string pAtk = to_string(pAtkInt);
int sAtkInt = TestPlayer.getCurrentWeapon().get_scissorsAtk();
string sAtk = to_string(sAtkInt);
int rDefInt = TestPlayer.getCurrentArmour().get_rockDef();
string rDef = to_string(rDefInt);
int pDefInt = TestPlayer.getCurrentArmour().get_paperDef();
string pDef = to_string(pDefInt);
int sDefInt = TestPlayer.getCurrentArmour().get_scissorsDef();
string sDef = to_string(sDefInt);
int rAtkSpace = rAtk.size();
int pAtkSpace = pAtk.size();
int sAtkSpace = sAtk.size();
int allAtkSpace = rAtkSpace + pAtkSpace + sAtkSpace;
int rDefSpace = rDef.size();
int pDefSpace = pDef.size();
int sDefSpace = sDef.size();
int allDefSpace = rDefSpace + pDefSpace + sDefSpace;
    // creating a display to contain current important information
cout << "╔═════════════════════════════════════════════════════════════╗"<<endl;       //HUD is 63 wide, 2 are the walls
cout << "║ " << TestPlayer.get_name();
for (int i = 0; i < hudNameSpacer; i++){cout << " ";} //adding approrpriate spaces given name length
if (TestPlayer.get_HP() < 100 ){cout << " ";}             //adding appropriate spaces given current HP
if (TestPlayer.get_HP() < 10 ){cout << " ";}              //adding appropriate spaces given current HP
cout << TestPlayer.get_HP() << "/100" << "                "/*16 spaces*/;
if (currentLevel < 1000){cout << " ";}                                //adding appropriate spaces given current level (breaks after level 9999)
if (currentLevel < 100){cout << " ";}
if (currentLevel < 10){cout << " ";}
cout << "Level " << currentLevel << " " << "║" << endl;
cout<<"║ Wpn: " << TestPlayer.getCurrentWeapon().get_name();
for (int i = 0; i < hudWpnSpacer; i++){cout << " ";};
cout << "rATK " << rAtk << " ";
cout << "pATK " << pAtk << " ";
cout << "sATK " << sAtk;
for (int i = 0; i < 18 - allAtkSpace; i++){cout << " ";};
cout << "║";
cout << endl;
cout<<"║ Amr: " << TestPlayer.getCurrentArmour().getName();
for (int i = 0; i < hudAmrSpacer; i++){cout << " ";};
cout << "rDEF " << rDef << " ";
cout << "pDEF " << pDef << " ";
cout << "sDEF " << sDef;
for (int i = 0; i < 18 - allDefSpace; i++){cout << " ";};
cout << "║";
cout << endl;
cout <<"╚═════════════════════════════════════════════════════════════╝"<< endl;
}

