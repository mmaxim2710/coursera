#include <iostream>
#include <map>
#include <string>

void change_capital(std::map<std::string, std::string>& country_capital, const std::string& country, const std::string& capital) {
    bool is_found = false;
    for(auto i : country_capital) {
        if(i.first == country) {
            is_found = true;
            if(i.second == capital) {
                std::cout << "Country " << country << " hasn't changed its capital" << std::endl;
            }
            else {
                std::cout << "Country " << country << " has changed its capital from " << i.second << " to " << capital << std::endl;
                country_capital[country] = capital;
            }
        }
    }
    if(is_found == false) {
        country_capital[country] = capital;
        std::cout << "Introduce new country " << country << " with capital " << capital << std::endl;
    }
}

void rename(std::map<std::string, std::string>& country_capital, std::string& old_country_name, const std::string& new_country_name) {
    if(old_country_name == new_country_name) {
        std::cout << "Incorrect rename, skip" << std::endl;
        return;
    }
    
    //bool country_is_already_exist = false;
    for(auto i : country_capital) {
        if(i.first == new_country_name) {
            std::cout << "Incorrect rename, skip" << std::endl;
            return;
        }
    }
    
    bool is_exist = false;
    
    for(auto c : country_capital) {
        if(c.first == old_country_name) {
            is_exist = true;
            std::cout << "Country " << c.first << " with capital " << c.second << " has been renamed to " << new_country_name << std::endl;
            country_capital[new_country_name] = c.second;
            country_capital.erase(old_country_name);
            break;
        }
    }
   
    if(is_exist == false) 
        std::cout << "Incorrect rename, skip" << std::endl;
}

void about(const std::map<std::string, std::string>& country_capital, const std::string& country) {
    bool is_found = false;
    for(auto c : country_capital) {
        if(c.first == country) {
            is_found = true;
            std::cout << "Country " << c.first << " has capital " << c.second << std::endl;
            break;
        }
    }

    if(is_found == false) {
        std::cout << "Country " << country << " doesn't exist" << std::endl; 
    }
}

void dump(const std::map<std::string, std::string>& country_capital) {
    if(country_capital.empty())
        std::cout << "There are no countries in the world" << std::endl;
    else {
        for(auto c : country_capital) {
            std::cout << c.first << "/" << c.second << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char** argv) {
    int number_of_requests;
    std::cin >> number_of_requests;
    std::map<std::string, std::string> country_capital;

    std::string name_of_request;
    std::string name_of_country;
    std::string name_of_capital;
    std::string new_capital_name;

    for(int i = 0; i < number_of_requests; i++) {
        std::cin >> name_of_request;
        if(name_of_request == "CHANGE_CAPITAL") {
            std::cin >> name_of_country >> name_of_capital;
            change_capital(country_capital, name_of_country, name_of_capital);
        } else if(name_of_request == "RENAME") {
            std::cin >> name_of_country >> new_capital_name;
            rename(country_capital, name_of_country, new_capital_name);
        } else if(name_of_request == "ABOUT") {
            std::cin >> name_of_country;
            about(country_capital, name_of_country);
        } else if(name_of_request == "DUMP") {
            dump(country_capital);
        }
    }
    return 0;
}