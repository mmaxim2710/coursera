#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector>

std::string FindName(const std::map<int, std::string>& names, const int& year) {
    auto next_iterator = names.upper_bound(year);
    if(next_iterator != names.begin()) {
        return (--next_iterator) -> second;
    }
    return "";
}


class Person {
    private:
        std::map<int, std::string> first_names;
        std::map<int, std::string> last_names;
    public:
        void ChangeFirstName(int year, const std::string& input_first_name) {
            first_names[year] = input_first_name;
        }

        void ChangeLastName(int year, const std::string& input_last_name) {
            last_names[year] = input_last_name;
        }

        std::string GetFullName(int year) {
            std::string first_name = FindName(first_names, year);
            std::string last_name = FindName(last_names ,year);
            if(first_name.empty() && last_name.empty()) {
                return "Incognito";
            } else if(first_name.empty()) {
                return last_name + " with unknown first name";
            } else if(last_name.empty()) {
                return first_name + " with unknown last name";
            } else {
                return first_name + " " + last_name;
            }
        }
};


int main() {
    Person person;
    
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
    
    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
    
    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        std::cout << person.GetFullName(year) << std::endl;
    }
    
    return 0;
}