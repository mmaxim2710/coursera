#include <iostream>
#include <vector>

template <typename T>
class Deque {
public:
    Deque() : size(0) {}

    bool Empty() const {
        return size == 0;
    }

    size_t Size() const {
        return size;
    }

    void PushFront(const T& element) {
        front_vector.push_back(element);
        size++;
    }

    void PushBack(const T& element) {
        back_vector.push_back(element);
        size++;
    }

    T& operator[](size_t index) {
        return front_vector.size() > index ?
               front_vector.at(front_vector.size() - 1 - index) :
               back_vector.at(index - front_vector.size());
    }

    const T& operator[](size_t index) const {
        return front_vector.size() > index ?
               front_vector.at(front_vector.size() - 1 - index) :
               back_vector.at(index - front_vector.size());
    }

    T& At(size_t index) {
        return front_vector.size() > index ?
               front_vector.at(front_vector.size() - 1 - index) :
               back_vector.at(index - front_vector.size());
    }

    const T& At(size_t index) const {
        return front_vector.size() > index ?
               front_vector.at(front_vector.size() - 1 - index) :
               back_vector.at(index - front_vector.size());
    }

    T& Front() {
        return front_vector.empty() ? back_vector.front() : front_vector.back();
    }

    const T& Front() const {
        return front_vector.empty() ? back_vector.front() : front_vector.back();
    }

    T& Back() {
        return back_vector.empty() ? front_vector.front() : back_vector.back();
    }

    const T& Back() const {
        return back_vector.empty() ? front_vector.front() : back_vector.back();
    }

private:
    std::vector<T> front_vector;
    std::vector<T> back_vector;
    size_t size;
};