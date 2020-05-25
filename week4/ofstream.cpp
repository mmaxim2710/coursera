#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    std::string to_out;
    if(in.is_open()) {
        while(getline(in, to_out)) {
            out << to_out << std::endl;
        }
    }
    return 0;
}