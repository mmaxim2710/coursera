#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// enum class Gender {
//     FEMALE,
//     MALE
// };

// struct Person {
//     int age;  // возраст
//     Gender gender;  // пол
//     bool is_employed;  // имеет ли работу
// };

// template <typename InputIt>
// int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
//   if (range_begin == range_end) {
//     return 0;
//   }
//   std::vector<typename InputIt::value_type> range_copy(range_begin, range_end);
//   auto middle = begin(range_copy) + range_copy.size() / 2;
//   nth_element(
//       begin(range_copy), middle, end(range_copy),
//       [](const Person& lhs, const Person& rhs) {
//         return lhs.age < rhs.age;
//       }
//   );
//   return middle->age;
// }

void PrintStats(std::vector<Person> persons) {
    { // all
        std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << std::endl;
    }

    { // FEMALE
        auto it = std::partition(persons.begin(), persons.end(), [](const Person& person){
            return person.gender == Gender::FEMALE;
        });

        std::cout << "Median age for females = " << ComputeMedianAge(persons.begin(), it) << std::endl;
    }

    { // MALE
        auto it = std::partition(persons.begin(), persons.end(), [](const Person& person){
            return person.gender == Gender::MALE;
        });

        std::cout << "Median age for males = " << ComputeMedianAge(persons.begin(), it) << std::endl;
    }

    { // employed females
        auto it = std::partition(persons.begin(), persons.end(), [](const Person& person){
            return person.gender == Gender::FEMALE && person.is_employed == true;
        });

        std::cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), it) << std::endl;
    }

    { // unemployed females
        auto it = std::partition(persons.begin(), persons.end(), [](const Person& person){
            return person.gender == Gender::FEMALE && person.is_employed == false;
        });

        std::cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), it) << std::endl;
    }

    { // employed males
        auto it = std::partition(persons.begin(), persons.end(), [](const Person& person){
            return person.gender == Gender::MALE && person.is_employed == true;
        });

        std::cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), it) << std::endl;
    }

    { // unemployed males
        auto it = std::partition(persons.begin(), persons.end(), [](const Person& person){
            return person.gender == Gender::MALE && person.is_employed == false;
        });

        std::cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), it) << std::endl;
    }
}

// int main() {
//     std::vector<Person> persons = {
//         {31, Gender::MALE, false},
//         {40, Gender::FEMALE, true},
//         {24, Gender::MALE, true},
//         {20, Gender::FEMALE, true},
//         {80, Gender::FEMALE, false},
//         {78, Gender::MALE, false},
//         {10, Gender::FEMALE, false},
//         {55, Gender::MALE, true},
//     };
    
//     PrintStats(persons);
//     return 0;
// }
