#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
    T* Allocate() {
        T* object;
        if(deallocated_.empty()) {
            object = new T;
        } else {
            object = deallocated_.front();
            deallocated_.pop();
        }
        allocated_.insert(object);
        return object;
    }
    T* TryAllocate() {
        T* object;
        if(deallocated_.empty()) {
            return nullptr;
        } else {
            object = deallocated_.front();
            deallocated_.pop();
        }
        allocated_.insert(object);
        return object;
    }

    void Deallocate(T* object) {
        if(allocated_.find(object) == allocated_.end()) {
            throw invalid_argument("");
        } else {
            deallocated_.push(object);
            allocated_.erase(object);
        }
    }

    ~ObjectPool() {
        for(auto& item : allocated_) {
            delete item;
        }
        while(!deallocated_.empty()) {
            delete deallocated_.front();
            deallocated_.pop();
        }
    }

private:
    set<T*> allocated_;
    queue<T*> deallocated_;
};

void TestObjectPool() {
    ObjectPool<string> pool;

    auto p1 = pool.Allocate();
    auto p2 = pool.Allocate();
    auto p3 = pool.Allocate();

    *p1 = "first";
    *p2 = "second";
    *p3 = "third";

    pool.Deallocate(p2);
    ASSERT_EQUAL(*pool.Allocate(), "second");

    pool.Deallocate(p3);
    pool.Deallocate(p1);
    ASSERT_EQUAL(*pool.Allocate(), "third");
    ASSERT_EQUAL(*pool.Allocate(), "first");

    pool.Deallocate(p1);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestObjectPool);
    return 0;
}