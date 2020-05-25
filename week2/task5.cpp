#include <iostream>
#include <string>
#include <vector>

void MoveStrings(std::vector<std::string>& sourse, std::vector<std::string>& destination) {
    for(auto s : sourse) {
        destination.push_back(s);
    }
    sourse.clear();
}

int main() {
    std::vector<std::string> sourse = {"a", "b", "c"};
    std::vector<std::string> destination = {"z"};
    MoveStrings(sourse, destination);
    for(int i = 0; i < destination.size(); i++) {
        std::cout << destination[i];
    }
    std::cout << std::endl;
    return 0;
}
