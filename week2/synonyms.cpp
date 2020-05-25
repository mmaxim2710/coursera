#include <iostream>
#include <map>
#include <string>

void add(std::map<std::string, std::string>& synonyms, const std::string& first_word, const std::string& second_word) {
    synonyms[first_word] = second_word;
    std::cout << "Added " << synonyms[first_word] << std::endl;
}

void check(const std::map<std::string, std::string>& synonyms, const std::string& word1, const std::string& word2) {
    for(auto i : synonyms) {
        std::cout << i.first << " " << i.second << std::endl;
    }
}

void print(const std::map<std::string, std::string>& synonyms) {
    for(auto i : synonyms) {
        std::cout << i.first << " " << i.second << std::endl;
    }
}

int main() {
    int Q;
    std::cin >> Q;

    for(int i = 0; i < Q; i++) {
        std::string command;
        std::cin >> command;
        std::map<std::string, std::string> synonyms;

        if(command == "ADD") {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            add(synonyms, word1, word2);
        } else if(command == "CHECK") {
            std::string word1, word2;
            std::cin >> word1 >> word2;
            check(synonyms, word1, word2);
        } else if(command == "PRINT") {
            print(synonyms);
        }
    }
    return 0;
}