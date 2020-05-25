#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

struct Student {
    std::string first_name;
    std::string second_name;
    int day, month, year;
};



int main() {
    int N, M = 0;
    std::vector<Student> students;
    std::cin >> N;
    std::string name, second_name;
    int day, month, year;
    for(int i = 0; i < N; i++) {
        std::cin >> name >> second_name >> day >> month >> year;
        students.push_back({name, second_name, day, month, year});
    }
    std::cin >> M;
    int id;
    std::string command;
    for(int i = 0; i < M; i++) {
        std::cin >> command >> id;
        if(id > students.size() || 0 >= id) {
            std::cout << "bad request" << std::endl;
        }
        else if(command == "name") {
            std::cout << students[id - 1].first_name << " " << students[id - 1].second_name << std::endl;
        }
        else if(command == "date") {
            std::cout << students[id - 1].day << "." << students[id - 1].month << "." << students[id - 1].year << std::endl;
        }
        else {
            std::cout << "bad request" << std::endl;
        }
    }
    return 0;
}