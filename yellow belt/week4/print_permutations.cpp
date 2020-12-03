#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {
    for(const auto& i : v) {
        os << i << " ";
    }
    os << '\n';

    return os;
}

int main() {
    int N;
    std::vector<int> v;
    std::cin >> N;
    v.resize(N);
    std::iota(v.rbegin(), v.rend(), 1);

    do {
        std::cout << v;
    } while (std::prev_permutation(v.begin(), v.end()));

    return 0;
}
