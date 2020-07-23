#include <vector>
#include <map>
#include <tuple>

using namespace std;

// struct Region {
//   string std_name;
//   string parent_std_name;
//   map<Lang, string> names;
//   int64_t population;
// };

// enum class Lang {
//   DE, FR, IT
// };

bool operator<(const Region& lhs, const Region& rhs) {
  return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
  int result = 0;
  map<Region, int> rep_count;
  for (const Region& r : regions) {
    result = max(result, ++rep_count[r]);
  }
  return result;
}
