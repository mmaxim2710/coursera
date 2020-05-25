#include <iostream>

int main() {
    int a, b = 0;
    std::cin >> a >> b;

    if(a > b) return 0;

    for(int i = a; i <= b; i++) {
        if (i % 2 == 0)
            std::cout << i << " ";
        else continue;
    }
    std::cout << "\n";

    return 0;
}
