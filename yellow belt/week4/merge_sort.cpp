#include <iostream>
#include <vector>
#include <algorithm>

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    auto size = range_end - range_begin;
    if(size < 2) {
        return;
    }
    std::vector<typename RandomIt::value_type> elements(range_begin, range_end);
    auto mid = begin(elements) + size / 2;
    MergeSort(elements.begin(), mid);
    MergeSort(mid, elements.end());
    std::merge(begin(elements), mid, mid, end(elements), range_begin);
}

int main() {
    std::vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(begin(v), end(v));
    for(const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    return 0;
}