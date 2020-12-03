#include <iostream>
#include <algorithm>

template <class ForwardIterator, class UnaryPredicate>
ForwardIterator max_element_if(ForwardIterator first, ForwardIterator last, UnaryPredicate pred) {
    ForwardIterator maxElemIt = std::find_if(first, last, pred);
    for (ForwardIterator cur = maxElemIt; cur != last; ++cur) {
        if (cur != maxElemIt && pred(*cur) && *maxElemIt < *cur) {
            maxElemIt = cur;
        }
    }
    return maxElemIt;
}