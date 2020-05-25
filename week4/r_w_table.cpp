#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

/* void PrintVector(const std::vector<int>& input_vector) {
    for(const int& v : input_vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
} */

int main() {
    std::ifstream is("input.txt");
    int n, m = 0;
    std::string data;
    is >> n >> m;
    is.ignore(1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m - 1; j++) {
            getline(is, data, ',');
            std::cout << std::setw(10) << data << " ";
        }
        getline(is, data);
        std::cout << std::setw(10) << data << std::endl;
    }

    return 0;
}