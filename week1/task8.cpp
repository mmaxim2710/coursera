#include <iostream>


int main(int argc, char** argv) {
    int a, b = 0;

    std::cin >> a >> b;

    while(a != 0 && b != 0) {
        if(a > b) a %= b;
        else b %= a;
    }

    std::cout << a + b << std::endl;
    return 0;
}