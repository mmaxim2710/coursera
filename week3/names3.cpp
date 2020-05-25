#include <iostream>
#include <string>
#include <map>
#include <vector>

struct FirstLastName {
    std::string first_name;
    std::string last_name;
};

class Person {
    private:
        std::map<int, FirstLastName> history_of_name;
    public:
        Person(const std::string& first_n, const std::string& last_n, int year) {
            history_of_name[year].first_name = first_n;
            history_of_name[year].last_name = last_n;
        }
        void ChangeFirstName(int year, const std::string& input_first_name) {
            //first_name = input_first_name;
            if(history_of_name.count(year) == 0) {
                history_of_name[year].last_name = "";
            }
            history_of_name[year].first_name = input_first_name;
        }

        void ChangeLastName(int year, const std::string& input_last_name) {
            //last_name = input_last_name;
            if(history_of_name.count(year) == 0) {
                history_of_name[year].first_name = "";
            }
            history_of_name[year].last_name = input_last_name;
        }

        std::string GetFullName(int year) const {
            std::string first_name_to_output = "";
            std::string last_name_to_output = "";
            
            if(history_of_name.size() == 0) {
                return "No person";
            } else {
                for(const auto& i : history_of_name) {
                    if(year < i.first) {
                        return "No person";
                    }
                    break;
                }
            }

            for (const auto& item : history_of_name) {
                if(item.second.first_name != "" && year >= item.first) {
                    first_name_to_output = item.second.first_name;
                }
                if(item.second.last_name != "" && year >= item.first) {
                    last_name_to_output = item.second.last_name;
                }
            }

            if(first_name_to_output == "") {
                return last_name_to_output + " with unknown first name";
            } else if (last_name_to_output == "") {
                return first_name_to_output + " with unknown last name";
            } else {
                return first_name_to_output + " " + last_name_to_output;
            }
        }

        std::string GetFullNameWithHistory(int year) const {
        if (history_of_name.size() == 0) {
            return "No person";
        } else {
            for (const auto& i : history_of_name) {
                if (year < i.first) {
                    return "No person";
                }
                break;
            }
        }

        std::string f_name = "";
        std::string l_name = "";
        std::vector<std::string> second_names; 
        std::vector<std::string> first_names;
        for (const auto& i : history_of_name) {

            if (i.first <= year && i.second.last_name != "") {
                if (i.second.last_name != l_name && l_name != "") second_names.push_back(l_name);
                l_name = i.second.last_name;
            }
            if (i.first <= year && i.second.first_name != "") {
                if (i.second.first_name != f_name && f_name != "") first_names.push_back(f_name);
                f_name = i.second.first_name;
            }
        }

        std::string second_names_string = "", first_names_string = "";
        if (second_names.size() > 0) {
            second_names_string += " (" + second_names[second_names.size() - 1];
            if (second_names.size() > 1) {
                for (int i = second_names.size() - 1; i > 0; --i) {
                    second_names_string += ", " + second_names[i - 1];
                }
            }
            second_names_string += ")";
        }

        if (first_names.size() > 0) {
            first_names_string += " (" + first_names[first_names.size() - 1];
            if (first_names.size() >1) {
                for (int i = first_names.size() - 1; i > 0; --i) {
                    first_names_string += ", " + first_names[i - 1];
                }
            }
            first_names_string += ")";
        }
 
        if (f_name == "") {
            return l_name + second_names_string + " with unknown first name";
        } else if (l_name == "") {
            return f_name + first_names_string + " with unknown last name";
        } else {
            return f_name + first_names_string + " " + l_name + second_names_string;
        }
    }
};

int main() {
  Person person("Polina", "Sergeeva", 1960);
  for (int year : {1959, 1960}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }
  
  person.ChangeFirstName(1965, "Appolinaria");
  person.ChangeLastName(1967, "Ivanova");
  for (int year : {1965, 1967}) {
    std::cout << person.GetFullNameWithHistory(year) << std::endl;
  }

  return 0;
}