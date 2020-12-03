#include "phone_number.h"
#include <stdexcept>

PhoneNumber::PhoneNumber(const string &international_number) {
    country_code_ = "";
    city_code_ = "";
    local_number_ = "";

    if(international_number[0] != '+') {
        throw std::invalid_argument("Number must begin with '+'");
    }

    int count = 0;
    // +7-910-7606779
    // +7-910-760-67-79

    for(int i = 1; i < international_number.size(); i++) {
        if(count < 2) {
            if(international_number[i] == '-') {
                count++;
                continue;
            }

            if(count == 0) {
                country_code_ += international_number[i];
            } else if(count == 1) {
                city_code_ += international_number[i];
            }
        } else {
            local_number_ += international_number[i];
        }
    }

    if(country_code_ == "" || city_code_ == "" || local_number_ == "") {
        throw std::invalid_argument("loh");
    }
}

string PhoneNumber::GetCountryCode() const {
    return country_code_;
}

string PhoneNumber::GetCityCode() const {
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
    return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
/*
#include <iostream>

int main() {
    PhoneNumber ph("+7-910-760-67-79");
    std::cout << ph.GetCountryCode() << " " << ph.GetCityCode() << " " << ph.GetLocalNumber() << std::endl;
    std::cout << ph.GetInternationalNumber() << std::endl;
    return 0;
}
*/