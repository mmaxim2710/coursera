#include <iostream>
#include <cctype>
#include <locale>
#include <vector>
#include <algorithm>
#include <string>

class SortPredicate {
public:

    bool operator()(const std::string& lhs, const std::string& rhs) const {
        std::string lhcLower(lhs);
        std::string rhcLower(rhs);
        std::transform(lhs.begin(), lhs.end(), lhcLower.begin(), ::tolower);
        std::transform(rhs.begin(), rhs.end(), rhcLower.begin(), ::tolower);
        return lhcLower < rhcLower;
    }
};

void print_vector(const std::vector<std::string>& input) {
    for(const auto& i : input) {
        std::cout << (std::string)i << " ";
    }
    std::cout << std::endl;
}


int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> words;

    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        words.push_back(s);
    }
    
    sort(words.begin(), words.end(), SortPredicate());

    print_vector(words);

    return 0;
}