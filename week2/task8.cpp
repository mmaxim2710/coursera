#include <iostream>
#include <vector>

void input_vector(std::vector<int>& vector, int num) {
    for(int i = 0; i < num; i++) {
        std::cin >> vector[i];
    }
}

void print_vector(const std::vector<int>& vector) {
    for(auto v : vector) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int average_temp(std::vector<int> vector) {
    int sum = 0;
    for(auto i : vector) {
        sum += i;
    }

    return sum / vector.size();
}

int main() {
    int num_of_days;
    std::cin >> num_of_days;
    std::vector<int> days(num_of_days);
    input_vector(days, num_of_days);

    int avr = average_temp(days);
    num_of_days = 0;
    std::vector<int> result_temp;

    for(int i = 0; i < days.size(); i++) {
        if(days[i] > avr) {
            num_of_days++;
            result_temp.push_back(i);
        }
    }

    std::cout << num_of_days << std::endl;
    print_vector(result_temp);

    return 0;
}