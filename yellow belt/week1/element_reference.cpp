#include <iostream>
#include <map>
#include <string>
#include <stdexcept>

template <typename T, typename U>
U& GetRefStrict(std::map<T, U>& map, T key) {
    if(map.count(key) == 0) {
        throw std::runtime_error("invalid key");
    } else {
        return map[key];
    }
}

int main(int argc, char** argv) {
    std::map<int, std::string> m = {{0, "value"}};
    std::string& item = GetRefStrict(m, 0);
    item = "newvalue";
    std::cout << m[0] << std::endl;
    return 0;
}