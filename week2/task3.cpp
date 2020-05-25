#include <iostream>
#include <string>
#include <vector>

bool IsPalindrom(std::string str) {
    for (int i = 0, j = str.size() - 1; i <= (str.size() / 2) && j >= (str.size() / 2); i++, j--) {
        if (str[i] == str[j]) continue;
        else return false;
    }
    return true;
}

std::vector<std::string> PalindromFilter (std::vector<std::string> words, int minLength) {
    std::vector<std::string> result;
    for (auto w : words) {
        if(IsPalindrom(w) && w.size() >= minLength) {
            result.push_back(w);
        }
    }
    return result;
}

int main(int argc, char** argv) {
    std::vector<std::string> words;
    int minLength;
    std::string word;

    for (int i = 0; i < 2; i++) {
        std::cin >> word;
        words.push_back(word);
    }
    std::cin >> minLength;

    std::vector<std::string> result = PalindromFilter(words, minLength);
    for(auto w : result) std::cout << w << ",";
    std::cout << std::endl;

    return 0;
}