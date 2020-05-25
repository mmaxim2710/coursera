#include <iostream>
#include <vector>

std::vector<int> Reversed(const std::vector<int>& v) {
    std::vector<int> temp;
    for(int i = v.size() - 1; i >= 0; i--) {
        temp.push_back(v[i]);
    }
    return temp;
}

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::vector<int> temp = Reversed(v);
    for(auto t : temp) std::cout << t << " ";
    std::cout << std::endl;
    return 0;
}