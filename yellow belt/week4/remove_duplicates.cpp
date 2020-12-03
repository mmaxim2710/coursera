#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void RemoveDuplicates(std::vector<T>& v) {
    std::sort(v.begin(), v.end());
    auto it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());
}

int main() {
    std::vector<int> v1 = {6, 4, 7, 6, 4, 4, 0, 1};
    RemoveDuplicates(v1);
    for (int x : v1) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
    std::vector<std::string> v2 = {"C", "C++", "C++", "C", "C++"};
    RemoveDuplicates(v2);
    for (const std::string& s : v2) {
        //std::cout << s << " ";
    }
    std::cout << std::endl;
    return 0;
}