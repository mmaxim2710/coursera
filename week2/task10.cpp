#include <iostream>
#include <vector>
#include <string>

void init_vector(std::vector<std::vector<std::vector<std::string>>>& input) {

    input.resize(12);
    input[0].resize(31);
    input[1].resize(28);
    input[2].resize(31);
    input[3].resize(30);
    input[4].resize(31);
    input[5].resize(30);
    input[6].resize(31);
    input[7].resize(31);
    input[8].resize(30);
    input[9].resize(31);
    input[10].resize(30);
    input[11].resize(31);
}

void add(std::vector<std::vector<std::vector<std::string>>>& input, std::string str, int day, const int& current_month) {

    if(current_month == 0 || current_month == 2 || current_month == 4
    || current_month == 6 || current_month == 7 || current_month == 9
    || current_month == 11) {
        if(day <= 31) {
            input[current_month][day - 1].push_back(str);
        }
    }
    else if(current_month == 1) {
        if(day <= 28) {
            input[current_month][day - 1].push_back(str);
        }
    }
    else if(current_month == 3 || current_month == 5 || current_month == 8 || current_month == 10) {
        if(day <= 30) {
            input[current_month][day - 1].push_back(str);
        }
    }
}

// dump(vector, day, month)
void dump(const std::vector<std::vector<std::vector<std::string>>>& input, int day, const int& current_month) {
    int count_of_cases = 0;

    std::cout << input[current_month][day - 1].size() << " ";

    for(int i = 0; i < input[current_month][day - 1].size(); i++) {
        std::cout << input[current_month][day - 1][i] << " ";
    }
    std::cout << std::endl;
}

std::vector<std::vector<std::vector<std::string>>> next(std::vector<std::vector<std::vector<std::string>>>& input, int& current_month) {

   std::vector<std::vector<std::vector<std::string>>> next_month;
   init_vector(next_month);

    if(current_month == 0) {
        for(int i = 0; i < 28; i++) {
            for(int j = 0; j < input[current_month][i].size(); j++) {
                next_month[current_month + 1][i].push_back(input[current_month][i][j]);
            }
        }

        for(int i = 0; i < input[current_month][29].size(); i++) {
            next_month[current_month + 1][27].push_back(input[current_month][29][i]);
        }
        for(int i = 0; i < input[current_month][30].size(); i++) {
            next_month[current_month + 1][27].push_back(input[current_month][30][i]);
        }
   }
   else if(current_month == 2 || current_month == 4 ||current_month == 7 || current_month == 9) {
       for(int i = 0; i < 30; i++) {
            for(int j = 0; j < input[current_month][i].size(); j++) {
                next_month[current_month + 1][i].push_back(input[current_month][i][j]);
            }
        }
       for(int i = 0; i < input[current_month][30].size(); i++) {
            next_month[current_month + 1][29].push_back(input[current_month][30][i]);
        }

   }
   else if(current_month == 6) {
       for(int i = 0; i < 31; i++) {
            for(int j = 0; j < input[current_month][i].size(); j++) {
                next_month[current_month + 1][i].push_back(input[current_month][i][j]);
            }
        }
   }
   else if(current_month == 11) {
       for(int i = 0; i < 31; i++) {
            for(int j = 0; j < input[current_month][i].size(); j++) {
                next_month[0][i].push_back(input[current_month][i][j]);
            }
        }
   }
   else if(current_month == 1) {
       for(int i = 0; i < 28; i++) {
            for(int j = 0; j < input[current_month][i].size(); j++) {
                next_month[current_month + 1][i].push_back(input[current_month][i][j]);
            }
        }
   }
   else {
       for(int i = 0; i < 30; i++) {
            for(int j = 0; j < input[current_month][i].size(); j++) {
                next_month[current_month + 1][i].push_back(input[current_month][i][j]);
            }
        }
   }
   if(current_month == 11) current_month = 0;
   else current_month++;


   return next_month;
}

int main() {

    std::vector<std::vector<std::vector<std::string>>> current_month(12);
    init_vector(current_month);
    //std::vector<std::vector<std::vector<std::string>>> next_month(12);

    std::string command;
    std::string todo;
    int day_todo;
    int day_to_output;

    int number_of_command;

    int int_current_month = 0;

    std::cin >> number_of_command;

    for(int i = 0; i < number_of_command; i++) {
        std::cin >> command;
        if(command == "ADD") {
            std::cin >> day_todo;
            std::cin >> todo;
            add(current_month, todo, day_todo, int_current_month);
        }
        else if(command == "DUMP") {
            std::cin >> day_to_output;
            dump(current_month, day_to_output, int_current_month);
        }
        else if(command == "NEXT") {
            current_month = next(current_month, int_current_month);
        }
    }
    return 0;
}