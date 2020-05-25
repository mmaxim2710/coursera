#include <iostream>
#include <string>

int main(int argc, char** argv) {
    std::string str;
    std::cin >> str;

    int count, i = 0;

    for (auto c : str) {
        if (c == 'f') {
            i++;
        }
        if(i == 2) {
            std::cout << count << std::endl;
            break;
        }
        count++;
    }
    if(i == 1) std::cout << "-1" << std::endl;
    if(i == 0) std::cout << "-2" << std::endl;
    return 0;
}