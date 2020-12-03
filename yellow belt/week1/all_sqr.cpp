#include <iostream>
#include <vector>
#include <map>
#include <utility>

template <typename T> std::vector<T> Sqr(const std::vector<T>& vec);
template <typename T, typename U> std::map<T, U> Sqr(const std::map<T, U>& map);
template <typename T, typename U> std::pair<T, U> Sqr(const std::pair<T, U>& pair);
template <typename T> T Sqr(T arg);

template <typename T>
T Sqr(T arg) {
    return arg * arg;
}

template <typename T>
std::vector<T> Sqr(const std::vector<T>& vec) {
    std::vector<T> out_vec;
    for(const auto& item : vec) {
        out_vec.push_back(Sqr(item));
    }
    return out_vec;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, std::vector<T> vec) {
    //bool first = true;
    for(const auto& v : vec) {
        os << v << " ";
    }
    return os;
}

template <typename T, typename U>
std::map<T, U> Sqr(const std::map<T, U>& map) {
    std::map<T, U> out_map;
    for(const auto& m : map) {
        out_map[m.first] = Sqr(m.second);
    }
    return out_map;
}

template <typename T, typename U>
std::ostream& operator<< (std::ostream& os, std::map<T, U> map) {
    for(const auto& m : map) {
        os << m.first << " " << m.second << std::endl; 
    }
    return os;
}

template <typename T, typename U> std::pair<T, U> Sqr(const std::pair<T, U>& pair) {
    std::pair<T, U> out_pair;
    out_pair.first = Sqr(pair.first);
    out_pair.second = Sqr(pair.second);
    return out_pair;
}

template <typename T, typename U>
std::ostream& operator<< (std::ostream& os, std::pair<T, U> pair) {
    os << pair.first << " " << pair.second;
    return os;
}

// int main() {
//     std::cout << "vector: " << std::endl;
//     std::vector<int> v = {1, 2, 3};
//     std::cout << Sqr(v) << std::endl;

//     // std::cout << "map: " << std::endl;
//     // std::map<int, int> m = {{1, 2}, {3, 4}, {5, 6}};
//     // std::cout << Sqr(m);

//     // int a = 5;
//     // std::cout << "int:" << std::endl;
//     // std::cout << Sqr(5) << std::endl;

//     std::cout << "map of pairs:" << std::endl;
//     std::map<int, std::pair<int, int>> map_of_pairs = {
//         {4, {2, 2}},
//         {7, {4, 3}}
//     };
//     std::cout << Sqr(map_of_pairs);
    
//     return 0;
// }