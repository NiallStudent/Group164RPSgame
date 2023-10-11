#include <iostream>
#include "Actor.h"
#include "Enemy.h"

using namespace std;

Enemy* createEnemyList(){

Enemy* enemyList = new Enemy[10];

Enemy grizzlyBear1("Grizzly Bear",30,10,10,15,8,15,10,
"It looks like it's about to charge headfirst",
"It opens its arms wide and advances",
"It readies its claws and rushes at you on its hind legs",
"It looks ready to meet your next attack with its thick skull",
"It opens its arms wide and waits for your next move",
"It takes a defensive stance and readies its claws"
);

Enemy troll1("Troll", 35, 15, 10, 10, 10, 8, 15,
"It readies its club",
"You notice its hand on a length of rope",
"It gnashes its teeth",
"It readies its club",
"It takes a defensive posture and you think you spot some rope in its hand",
"You spot a glint of well polished steel");

Enemy merfolk1("Merfolk Trapper", 40, 8, 20, 12, 17, 12, 5,
"It swings the butt of its trident at you",
"It smirks at you then approaches fast",
"It points the trident straight at your chest then charges",
"It turns the flat size of its trident towards you",
"It takes a defensive posture, hand on something on its belt",
"It takes guard, its trident pointed at you");


Enemy grizzlyBear2("Grizzly Bear",30,10,10,15,8,15,10,
"It looks like it's about to charge headfirst",
"It opens its arms wide and advances",
"It readies its claws and rushes at you on its hind legs",
"It looks ready to meet your next attack with its thick skull",
"It opens its arms wide and waits for your next move",
"It takes a defensive stance and readies its claws"
);

Enemy troll2("Troll", 35, 15, 10, 10, 10, 8, 15,
"It readies its club",
"You notice its hand on a length of rope",
"It gnashes its teeth",
"It readies its club",
"It takes a defensive posture and you think you spot some rope in its hand",
"You spot a glint of well polished steel");

Enemy merfolk2("Merfolk Trapper", 40, 8, 20, 12, 17, 12, 5,
"It swings the butt of its trident at you",
"It smirks at you then approaches fast",
"It points the trident straight at your chest then charges",
"It turns the flat size of its trident towards you",
"It takes a defensive posture, hand on something on its belt",
"It takes guard, its trident pointed at you");


Enemy grizzlyBear3("Grizzly Bear",30,10,10,15,8,15,10,
"It looks like it's about to charge headfirst",
"It opens its arms wide and advances",
"It readies its claws and rushes at you on its hind legs",
"It looks ready to meet your next attack with its thick skull",
"It opens its arms wide and waits for your next move",
"It takes a defensive stance and readies its claws"
);

Enemy troll3("Troll", 35, 15, 10, 10, 10, 8, 15,
"It readies its club",
"You notice its hand on a length of rope",
"It gnashes its teeth",
"It readies its club",
"It takes a defensive posture and you think you spot some rope in its hand",
"You spot a glint of well polished steel");

Enemy merfolk3("Merfolk Trapper", 40, 8, 20, 12, 17, 12, 5,
"It swings the butt of its trident at you",
"It smirks at you then approaches fast",
"It points the trident straight at your chest then charges",
"It turns the flat size of its trident towards you",
"It takes a defensive posture, hand on something on its belt",
"It takes guard, its trident pointed at you");

Enemy knight("Dark Knight", 70, 15, 15, 20, 20, 20, 20,
"He smirks and charges, something dull in hand",
"He charges with a sinister look in his eyes",
"He smirks and charges, something shiny in hand",
"He points his shoulder guard towards you",
"He readies his sword and mace in an x shape, ready to catch your attack",
"He takes a defensive stance and you see a bright flash");
enemyList[0] = grizzlyBear1;
enemyList[1] = troll1;
enemyList[2] = merfolk1;
enemyList[3] = grizzlyBear2;
enemyList[4] = troll2;
enemyList[5] = merfolk2;
enemyList[6] = grizzlyBear3;
enemyList[7] = troll3;
enemyList[8] = merfolk3;
enemyList[9] = knight;



return enemyList;
};