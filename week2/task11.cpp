#include <iostream>
#include <map>
#include <string>
#include <algorithm>

void BuildCharMap(std::map<char, int>& map, const std::string& word) {
    for(auto w : word) {
        ++map[w];
    }
}

void MapDelete(std::map<char, int>& map, const std::string& word) {
    for(auto w : word) {
        map.erase(w);
    }
}

int main(int argc, char** argv) {
    std::map<char, int> word_map1;
    std::map<char, int> word_map2;
    std::string word1;
    std::string word2;
    int num_of_pairs;

    std::cin >> num_of_pairs;
    for(int i = 0; i < num_of_pairs; i++) {
        std::cin >> word1 >> word2;
        BuildCharMap(word_map1, word1);
        BuildCharMap(word_map2, word2);
        if(word_map1 == word_map2) {
            std::cout << "YES" << std::endl;
        } else std::cout << "NO" << std::endl;
        MapDelete(word_map1, word1);
        MapDelete(word_map2, word2);
    }
    return 0;
}