#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
void Swap(T* first, T* second) {
    auto tmp = *first;
    *first = *second;
    *second = tmp;
}

template <typename T>
void SortPointers(vector<T*>& pointers) {
    sort(begin(pointers), end(pointers), [](T* lhs, T* rhs) {
        return *lhs < *rhs;
    });
}

template <typename T>
void ReversedCopy(T* source, size_t count, T* destination) {
    auto source_begin = source;
    auto source_end = source + count;
    auto dest_begin = destination;
    auto dest_end = destination + count;
    if (dest_begin >= source_end || dest_end <= source_begin) {
        reverse_copy(source_begin, source_end, dest_begin);
    } else if (dest_begin > source_begin) {
        for (size_t i = 0; source_begin + i < dest_begin; ++i) {
            *(dest_end - i - 1) = *(source_begin + i);
        }
        reverse(dest_begin, source_end);
    } else {
        for (size_t i = 0; source_end - i - 1 >= dest_end; ++i) {
            *(dest_begin + i) = *(source_end - i - 1);
        }
        reverse(source_begin, dest_end);
    }
}
