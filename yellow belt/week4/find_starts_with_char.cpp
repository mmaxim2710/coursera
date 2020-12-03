#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

template<typename RandomIt>
std::pair <RandomIt, RandomIt> FindStartsWith(RandomIt range_begin,
                                              RandomIt range_end,
                                              char prefix) {
    std::string lower({prefix});
    std::string upper({++prefix});
    return std::make_pair(std::lower_bound(range_begin, range_end, lower),
                          std::upper_bound(range_begin, range_end, upper));
}

template<typename RandomIt>
std::pair <RandomIt, RandomIt> FindStartsWith(RandomIt range_begin,
                                             RandomIt range_end,
                                             const std::string& prefix) {
    std::string upper({prefix});
    upper[prefix.size() - 1]++;
    return std::make_pair(std::lower_bound(range_begin, range_end, prefix),
                          std::lower_bound(range_begin, range_end, upper));
}

int main() {
    const std::vector <std::string> sorted_strings = {"moscow", "murmansk", "vologda"};

    const auto m_result = FindStartsWith(sorted_strings.begin(), sorted_strings.end(), 'm');
    for (auto it = m_result.first; it != m_result.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    const auto p_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
    std::cout << (p_result.first - begin(sorted_strings)) << " " << (p_result.second - begin(sorted_strings)) << std::endl;

    const auto z_result = FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
    std::cout << (z_result.first - begin(sorted_strings)) << " " << (z_result.second - begin(sorted_strings)) << std::endl;

// -----------------------------------------------------------------------------

    const vector<string> sorted_strings_2 = { "moscow", "motovilikha", "murmansk" };

    const auto mo_result = FindStartsWith(begin(sorted_strings_2), end(sorted_strings_2), "mo");
    for (auto it = mo_result.first; it != mo_result.second; ++it) {
        cout << *it << " ";
    }
    cout << endl;

    const auto mt_result = FindStartsWith(begin(sorted_strings_2), end(sorted_strings_2), "mt");
    cout << (mt_result.first - begin(sorted_strings_2)) << " " << (mt_result.second - begin(sorted_strings_2)) << endl;

    const auto na_result = FindStartsWith(begin(sorted_strings_2), end(sorted_strings_2), "na");
    cout << (na_result.first - begin(sorted_strings_2)) << " " << (na_result.second - begin(sorted_strings_2)) << endl;

    return 0;
}