#include "test_runner.h"

#include <cstdint>
#include <iterator>
#include <numeric>
#include <vector>
#include <iostream>
#include <utility>

using namespace std;

template <typename RandomIt>
void MakeJosephusPermutation(RandomIt first, RandomIt last, uint32_t step_size) {
    std::vector<typename RandomIt::value_type> pool;
    pool.reserve(last - first);
    for (auto it = first; it != last; it++) {
        pool.push_back(std::move(*it));
    }

    std::vector<size_t> pool_idx;
    pool_idx.reserve(last - first);
    iota(pool_idx.begin(), pool_idx.end(), 0);
    size_t pos = 0;

    for (auto it = first; it != last; it++) {
        *it = std::move(pool[pool_idx[pos]]);
        pool_idx.erase(pos + pool_idx.begin());
        if (pool_idx.empty()) {
            break;
        }
        pos = (pos + step_size - 1) % pool_idx.size();
    }
}

vector<int> MakeTestVector() {
  vector<int> numbers(10);
  iota(begin(numbers), end(numbers), 0);
  return numbers;
}

void TestIntVector() {
  const vector<int> numbers = MakeTestVector();
  {
    vector<int> numbers_copy = numbers;
    MakeJosephusPermutation(begin(numbers_copy), end(numbers_copy), 1);
    ASSERT_EQUAL(numbers_copy, numbers);
  }
  {
    vector<int> numbers_copy = numbers;
    MakeJosephusPermutation(begin(numbers_copy), end(numbers_copy), 3);
    ASSERT_EQUAL(numbers_copy, vector<int>({0, 3, 6, 9, 4, 8, 5, 2, 7, 1}));
  }
}

// Р­С‚Рѕ СЃРїРµС†РёР°Р»СЊРЅС‹Р№ С‚РёРї, РєРѕС‚РѕСЂС‹Р№ РїРѕРјРѕР¶РµС‚ РІР°Рј СѓР±РµРґРёС‚СЊСЃСЏ, С‡С‚Рѕ РІР°С€Р° СЂРµР°Р»РёР·Р°С†РёСЏ
// С„СѓРЅРєС†РёРё MakeJosephusPermutation РЅРµ РІС‹РїРѕР»РЅСЏРµС‚ РєРѕРїРёСЂРѕРІР°РЅРёРµ РѕР±СЉРµРєС‚РѕРІ.
// РЎРµР№С‡Р°СЃ РІС‹, РІРѕР·РјРѕР¶РЅРѕ, РЅРµ РїРѕРЅРёРјР°РµС‚Рµ РєР°Рє РѕРЅ СѓСЃС‚СЂРѕРµРЅ, РѕРґРЅР°РєРѕ РјС‹ СЂР°СЃСЃРєР°Р¶РµРј,
// РїРѕС‡РµРјСѓ РѕРЅ СѓСЃС‚СЂРѕРµРЅ РёРјРµРЅРЅРѕ С‚Р°Рє, РґР°Р»РµРµ РІ Р±Р»РѕРєРµ РїСЂРѕ move-СЃРµРјР°РЅС‚РёРєСѓ вЂ”
// РІ РІРёРґРµРѕ В«РќРµРєРѕРїРёСЂСѓРµРјС‹Рµ С‚РёРїС‹В»

struct NoncopyableInt {
  int value;

  NoncopyableInt(int value) : value(value) {}

  NoncopyableInt(const NoncopyableInt&) = delete;
  NoncopyableInt& operator=(const NoncopyableInt&) = delete;

  NoncopyableInt(NoncopyableInt&&) = default;
  NoncopyableInt& operator=(NoncopyableInt&&) = default;
};

bool operator == (const NoncopyableInt& lhs, const NoncopyableInt& rhs) {
  return lhs.value == rhs.value;
}

ostream& operator << (ostream& os, const NoncopyableInt& v) {
  return os << v.value;
}

void TestAvoidsCopying() {
  vector<NoncopyableInt> numbers;
  numbers.push_back({1});
  numbers.push_back({2});
  numbers.push_back({3});
  numbers.push_back({4});
  numbers.push_back({5});

  MakeJosephusPermutation(begin(numbers), end(numbers), 2);

  vector<NoncopyableInt> expected;
  expected.push_back({1});
  expected.push_back({3});
  expected.push_back({5});
  expected.push_back({4});
  expected.push_back({2});

  ASSERT_EQUAL(numbers, expected);
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestIntVector);
  RUN_TEST(tr, TestAvoidsCopying);
  return 0;
}