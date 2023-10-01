#include <iostream>
#include <vector>
#include <string>

class MyObject {
public:
    MyObject(const std::string& name) : name(name) {}
    void printName() {
        std::cout << "Object name: " << name << std::endl;
    }
private:
    std::string name;
};

int main() {
    std::vector<MyObject> objects;
    int numberOfObjects = 5;

    //code to generate new items with automatically generated names. add it to vector
     
    for (int i = 0; i < numberOfObjects; ++i) {
        std::string objectName = "Object_" + std::to_string(i);
        objects.emplace_back(objectName);
    }

    for (int i = 0; i < numberOfObjects; i++)
    {
        objects[i].printName();
    }
    

    return 0;
}
