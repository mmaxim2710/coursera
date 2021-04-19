#ifndef COURSERA_STACK_VECTOR_H
#define COURSERA_STACK_VECTOR_H

#include <stdexcept>
#include <array>

using namespace std;

template <typename T, size_t N>
class StackVector {
public:
    explicit StackVector(size_t a_size = 0) {
        if (a_size > N) {
            throw std::invalid_argument("");
        } else {
            capacity_ = N;
            size_ = a_size;
        }
    }

    T& operator[](size_t index) {
        return array_[index];
    }
    const T& operator[](size_t index) const {
        return array_[index];
    }

    T* begin() {
        return array_.begin();
    }
    T* end() {
        return array_.begin() + size_;
    }
    const T* begin() const {
        return array_.begin();
    }
    const T* end() const {
        return array_.begin() + size_;
    }

    size_t Size() const {
        return size_;
    }
    size_t Capacity() const {
        return capacity_;
    }

    void PushBack(const T& value) {
        if (Size() == Capacity()) {
            throw std::overflow_error("");
        }

        array_[size_] = value;
        size_++;
    }
    T PopBack() {
        if (size_ == 0) {
            throw underflow_error("Empty");
        } else {
            --size_;
            return array_[size_];
        }
    }

private:
    size_t size_;
    size_t capacity_;
    array<T, N> array_;
};

#endif //COURSERA_STACK_VECTOR_H
