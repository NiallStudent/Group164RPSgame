#include <vector>
#include <iostream>
using namespace std;

class Item
{
private:
    string name;
public:
    Item():Item("Default item"){};
    Item(string name){
        this->name = name;
    };
    ~Item(){};
    string getName(){
        return this->name;
    }
};

