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

    auto one_third = elements.begin() + size / 3;
    auto two_third = elements.begin() + size * 2 / 3;

    MergeSort(elements.begin(), one_third);
    MergeSort(one_third, two_third);
    MergeSort(two_third, elements.end());

    std::vector<typename RandomIt::value_type> temp;
    std::merge(elements.begin(), one_third, one_third, two_third, std::back_inserter(temp));
    std::merge(temp.begin(), temp.end(), two_third, elements.end(), range_begin);
}

int main() {
    std::vector<int> v = {6, 3, 5, 5, 2, 6, 3, 2, 1, 1, 2, 3, 1, 2, 3};
    MergeSort(v.begin(), v.end());
    for(const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    return 0;
}