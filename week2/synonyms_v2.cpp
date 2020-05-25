#include <iostream>
#include <vector>
#include <set>
#include <map>

//using namespace std;

int main() {
	std::set<std::vector<std::string>> set_of_synonyms;
	std::map<std::string, unsigned int> counter_of_synonyms;
    
    int n;
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		std::string command;
		std::cin >> command;

		if (command == "COUNT") {
            std::string word;
            std::cin >> word;
			std::cout << counter_of_synonyms[word] << "\n";
		} else {
            std::string word1;
            std::cin >> word1;
			std::string word2;
			std::cin >> word2;
			std::vector<std::string> synonym1_synonym2 = {word1, word2};
			std::vector<std::string> synonym2_synonym1 = {word2, word1};

            if (command == "CHECK") {
				if (set_of_synonyms.count(synonym1_synonym2) || set_of_synonyms.count(synonym2_synonym1)) {
					std::cout << "YES" << std::endl;
                } else  {
                    std::cout << "NO" << std::endl;
                }
			} else if (command == "ADD") {
				if (!set_of_synonyms.count(synonym2_synonym1) && !set_of_synonyms.count(synonym1_synonym2)) {
					set_of_synonyms.insert(synonym1_synonym2);

					++counter_of_synonyms[word1];
					++counter_of_synonyms[word2];
				}
			}
		}
	}
	return 0;
}