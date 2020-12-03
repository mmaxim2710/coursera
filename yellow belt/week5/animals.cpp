#include <iostream>
#include <string>

class Animal {
public:
    // ваш код
    Animal(const std::string& s = "animal") : Name(s) {}

    const std::string Name;
};


class Dog : public Animal {
public:
    // ваш код
    Dog(const std::string& s) : Animal(s) {
    }
    void Bark() {
        std::cout << Name << " barks: woof!" << std::endl;
    }
};

int main() {
    Dog d{"tina"};
    d.Bark();
    return 0;
}