#pragma once

#include <cstdlib>
#include <algorithm>

template <typename T>
class SimpleVector {
public:
    SimpleVector() : begin_(nullptr), end_(nullptr), size(0), capacity(0) {
    }
    explicit SimpleVector(size_t size) {
        this->size = size;
        capacity = size;
        begin_ = new T[size];
        end_ = begin_ + size;
    }
    ~SimpleVector() {
        delete [] begin_;
    }

    T& operator[](size_t index) {
        return *(begin_ + index);
    }

    T* begin() {
        return begin_;
    }
    T* end() {
        return end_;
    }

    const T* begin() const {
        return begin_;
    }
    const T* end() const {
        return end_;
    }

    size_t Size() const {
        return size;
    }
    size_t Capacity() const {
        return capacity;
    }
    void PushBack(const T& value) {
        if(Size() == 0) {
            capacity = 1;
            begin_ = new T[capacity];
        } else if(Size() == Capacity()) {
            T* old_begin_ = begin_;
            capacity = 2 * Size();
            begin_ = new T[capacity];
            std::copy(old_begin_, old_begin_ + size, begin_);
            delete [] old_begin_;
        }
        begin_[size++] = value;
        end_ = begin_ + size;
    }

private:
    T* begin_;
    T* end_;
    //T* curr;
    size_t size;
    size_t capacity;
};