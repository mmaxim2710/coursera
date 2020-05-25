#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class SortedStrings {
    public:
        void AddString(const std::string& input_string) {
            strings.push_back(input_string);
        }
        std::vector<std::string> GetSortedStrings() {
            std::sort(strings.begin(), strings.end());
            return strings;
        }
    private:
    std::vector<std::string> strings;
};

void print_str(SortedStrings str) {
    std::vector<std::string> result = str.GetSortedStrings();
    for(const auto& i : result) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
  SortedStrings strings;
  
  strings.AddString("first");
  strings.AddString("third");
  strings.AddString("second");
  print_str(strings);
  
  strings.AddString("second");
  print_str(strings);
  
  return 0;
}