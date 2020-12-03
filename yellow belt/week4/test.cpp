#include <iostream>
#include <iterator>
#include <vector>

template<typename It>
std::vector<typename It::value_type> merge(const It begin, const It mid, const It end) {
    std::vector<typename It::value_type> v;
    It it_l{ begin }, it_r{ mid };
    const It it_mid{ mid }, it_end{ end };
    while (it_l != it_mid && it_r != it_end)
    {
        v.push_back((*it_l <= *it_r) ? *it_l++ : *it_r++);
    }   
    v.insert(v.end(), it_l, it_mid);    
    v.insert(v.end(), it_r, it_end);
    return std::move(v);
}

template<typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
    auto size = std::distance(range_begin, range_end);
    if (size < 2)
        return;

    auto mid = std::next(range_begin, size / 2);
    MergeSort(range_begin, mid);
    MergeSort(mid, range_end);
    auto &&v = merge(range_begin, mid, range_end);
    std::move(v.cbegin(), v.cend(), range_begin);
}

int main() {
    std::vector<int> v{6, 4, 7, 6, 4, 4, 0, 1};
    MergeSort(v.begin(), v.end());
    for(const auto& x : v) {
        std::cout << x << " ";
    }
    std::cout << '\n';
    return 0;
}