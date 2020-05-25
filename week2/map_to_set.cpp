#include <iostream>
#include <map>
#include <set>
#include <string>

std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& input_map) {
    std::set<std::string> out_set;
    for(auto m : input_map) {
        out_set.insert(m.second);
    }
    return out_set;
}