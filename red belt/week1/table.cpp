#include <iostream>
#include <vector>
#include <utility>
#include <exception>
#include "test_runner.h"

using namespace std;

template <typename T>
class Table {
private:
    size_t columns, rows;
    vector<vector<T>> table;
public:
    Table () : columns(0), rows(0) {}
    Table (const size_t& c, const size_t& r) {
        if (c == 0 || r == 0) {
            columns = 0;
            rows = 0;
        } else if (c > 0 || r > 0) {
            columns = c;
            rows = r;
        } else {
            throw std::logic_error("Negative value of row or column");
        }
        table.resize(columns);
        for(vector<T>& t : table) {
            t.resize(rows);
        }
    }

    vector<T>& operator[] (size_t index) {
        return table[index];
    }
    const vector<T>& operator[] (size_t index) const {
        return table[index];
    }

    void Resize(const size_t& c, const size_t& r) {
        columns = c;
        rows = r;
        table.resize(columns);
        for(vector<T>& t : table) {
            t.resize(rows);
        }
    }

    pair<size_t, size_t> Size() const {
        return make_pair(columns, rows);
    }
};


void TestTable() {
    Table<int> t(1, 1);
    ASSERT_EQUAL(t.Size().first, 1u);
    ASSERT_EQUAL(t.Size().second, 1u);
    t[0][0] = 42;
    ASSERT_EQUAL(t[0][0], 42);
    t.Resize(3, 4);
    ASSERT_EQUAL(t.Size().first, 3u);
    ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
    TestRunner tr;
    RUN_TEST(tr, TestTable);
    return 0;
}