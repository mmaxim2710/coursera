#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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

int main(int argc, const char * argv[]) {

    std::vector<std::string> strVec = {"Alpha", "Beta", "Gamma", "aaa", "bbb", "ccc"};
    std::sort(strVec.begin(), strVec.end(), SortPredicate());

    for(const std::string& item : strVec) {
        std::cout << item << std::endl;
    }
    return 0;
}