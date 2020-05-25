#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in("input.txt");
    std::string to_output;
    if(in.is_open()) {
        while(getline(in, to_output)) {
            std::cout << to_output << std::endl;
        }
    }
    return 0;
}