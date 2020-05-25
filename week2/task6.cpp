#include <iostream>
#include <vector>

void Reverse(std::vector<int>& v) {
    std::vector<int> temp = v;
    for(int i = v.size() - 1, j = 0; i >= 0; i--, j++) {
        v[j] = temp[i];
    }
    
}

int main() {
    std::vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for(int i = 0; i <= numbers.size() - 1; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}