#include "inventory.h"
#include <iostream>
using namespace std;
#include <vector>

int main() {
/*     std::vector<int> numbers = {10, 20, 30, 40, 50};

    int target = 30; // The element you want to find the index of
    bool found = false;

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (numbers[i] == target) {
            std::cout << "Element " << target << " found at index " << i << std::endl;
            found = true;
            break; // Exit the loop since we found the element
        }
    }

    if (!found) {
        std::cout << "Element " << target << " not found in the vector." << std::endl;
    } */

    bool found = false;

    int vLength=10;

   Item* item1 = new Item;
   Item* item2 = new Item;
    

    vector<Item*> inventory;
    inventory.push_back(item1);
    inventory.push_back(item2);

    string nameMatch="item 2";

    for (size_t i = 0; i < inventory.size(); ++i) {
    cout<<i+1<<": "<<inventory[i]->getName()<<endl;
    }


    return 0;
}