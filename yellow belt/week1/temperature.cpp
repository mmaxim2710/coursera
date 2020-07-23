#include <iostream>
#include <vector>
#include <cstdint>

int main(int argc, char** argv) {
    unsigned int num_of_operations;
    std::cin >> num_of_operations;
    std::vector<int32_t> temperature;

    for(size_t i = 0; i < num_of_operations; i++) {
        int32_t temp;
        std::cin >> temp;
        temperature.push_back(temp);
    }

    int64_t avg = 0;
    for(const auto& t : temperature) {
        avg += t;
    }
    int64_t average = avg / static_cast<int64_t>(temperature.size());
    //std::cout << "[TEMP] average = " << average << std::endl;
    int count = 0;
    int num_of_days = 0;
    std::vector<int> days;
    for(const auto& t : temperature) {
        if(average < t) {
            days.push_back(count);
            num_of_days++;
        }
        count++;
    }

    std::cout << num_of_days << std::endl;
    for(const auto& d : days) {
        std::cout << d << " ";
    }
    std::cout << std::endl;
    return 0;
}