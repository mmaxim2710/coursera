#include <iostream>
#include <set>
#include <algorithm>

std::set<int>::const_iterator FindNearestElement(const std::set<int>& numbers, int border) {
    if(numbers.begin() == numbers.end()) {
        return numbers.end();
    }
    auto first_not_less = numbers.lower_bound(border);
    auto last_less = prev(first_not_less);
    if(first_not_less == numbers.begin()) {
        return first_not_less;
    }
    if(first_not_less == numbers.end()) {
        return last_less;
    }

    bool check = (border - *last_less <= *first_not_less - border);

    return check? last_less : first_not_less;
}

int main() {
    std::set<int> numbers = {1, 4, 6};
    std::cout << 
        *FindNearestElement(numbers, 0) << " " <<
        *FindNearestElement(numbers, 3) << " " <<
        *FindNearestElement(numbers, 5) << " " <<
        *FindNearestElement(numbers, 6) << " " <<
        *FindNearestElement(numbers, 100) << " " << std::endl;

    std::set<int> empty;

    std::cout << (FindNearestElement(empty, 8) == end(empty)) << std::endl;
    return 0;
}