#include <iostream>
#include <set>
#include <string>

int main(int argc, char** argv) {
    int num_of_strungs;
    std::cin >> num_of_strungs;
    std::set<std::string> set_of_strings;


    for(int i = 0; i < num_of_strungs; i++) {
        std::string string_to_insert;
        std::cin >> string_to_insert;
        set_of_strings.insert(string_to_insert);
    }

    std::cout << set_of_strings.size() << std::endl;
    return 0;
}