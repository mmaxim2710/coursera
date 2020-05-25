#include <iostream>

int Factorial(int arg) {
    int temp = 1;
    for (int i = 1; i <= arg; i++) {
        temp *= i;
    }
    return temp;
}

int main(int argc, char** argv) {
    int arg;
    std::cin >> arg;
    std::cout << Factorial(arg) << std::endl;
    return 0;
}