#include <iostream>
#include <vector>
#include <string>

class Item {
public:
    Item(const std::string& name, int value) : name(name), value(value) {}

    std::string getName() const {
        return name;
    }

    int getValue() const {
        return value;
    }

private:
    std::string name;
    int value;
};

class Player {
public:
    Player(const std::string& playerName) : playerName(playerName) {}

    void addItem(Item* item) {
        inventory.push_back(item);
    }

    void listInventory() const {
        std::cout << playerName << "'s Inventory:" << std::endl;
        for (const Item* item : inventory) {
            std::cout << "- " << item->getName() << " (Value: " << item->getValue() << ")" << std::endl;
        }
    }

private:
    std::string playerName;
    std::vector<Item*> inventory;
};

int main() {
    Player player("poppy");

    Item* item1 = new Item("Sword", 100);
    Item* item2 = new Item("Shield", 50);
    Item* item3 = new Item("Potion", 25);

    player.addItem(item1);
    player.addItem(item2);
    player.addItem(item3);

    player.listInventory();

    // Don't forget to free the memory allocated for items
    delete item1;
    delete item2;
    delete item3;

    return 0;
}