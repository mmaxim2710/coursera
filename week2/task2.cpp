#include <iostream>
#include <string>

bool IsPalindrom(std::string str) {
    for (int i = 0, j = str.size() - 1; i <= (str.size() / 2) && j >= (str.size() / 2); i++, j--) {
        if (str[i] == str[j]) continue;
        else return false;
    }
    return true;
}

int main() {
    std::string str;
    std::cin >> str;

    if(IsPalindrom(str))
        std::cout << "true" << std::endl;
    else
        std::cout << "false" << std::endl;
    
    return 0;
}