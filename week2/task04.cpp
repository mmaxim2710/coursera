#include <iostream>

void UpdateIfGreater(int first, int& second) {
    if (first > second) {
        first += second;
        second = first - second;
        first -= second;
    }
}

int main(int argc, char** argv) {
    int a = 4;
    int b = 2;
    std::cout << a << " " << b << std::endl;
    UpdateIfGreater(a, b);
    std::cout << a << " " << b << std::endl;
    return 0;
}