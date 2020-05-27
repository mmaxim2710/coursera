#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
#include <sstream>

class Date {
public:
  Date() : day(0), month(0), year(0) {
  }
  Date(const int& in_year, const int& in_month, const int& in_day) {
    year = in_year;
    if(in_month < 1 || in_month > 12) {
      throw std::logic_error("Month value is invalid: " + std::to_string(in_month));
    }
    month = in_month;
    if(in_day < 1 || in_day > 31) {
      throw std::logic_error("Day value is invalid: " + std::to_string(in_day));
    }
    day = in_day;
  }
  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }

private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  /* if(lhs.GetYear() < rhs.GetYear()) {
    return true;
  } else if(lhs.GetYear() > rhs.GetYear()) {
    return false;
  } else {
    if(lhs.GetMonth() < rhs.GetMonth()) {
      return true;
    } else if(lhs.GetMonth() > rhs.GetMonth()) {
      return false;
    } else {
      if(lhs.GetDay() < rhs.GetDay()) {
        return true;
      } else if(lhs.GetDay() >= rhs.GetDay()) {
        return false;
      }
    }
  } */
  return std::vector<int>{lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()} < std::vector<int>{rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
}

bool operator==(const Date& lhs, const Date& rhs) {
  return (lhs.GetDay() == rhs.GetDay()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetYear() == rhs.GetYear());
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << std::setw(4) << std::setfill('0') << date.GetYear() << "-" << std::setw(2) << std::setfill('0') << date.GetMonth() << "-" << std::setw(2) << std::setfill('0') << date.GetDay();
  return os;
}

/* std::istream& operator>>(std::istream& is, Date& date) {
  int day, month, year;
  if((is >> year) && (is.ignore(1)) && (is >> month) && (is.ignore(1)) && (is >> day)) {
    if(month < 1 && month > 12) {
      throw std::logic_error("Month value is invalid: " + month);
    }
    else if(day < 1 && day > 31) {
      throw std::logic_error("Day value is invalid: " + day);
    }
    else {
      date = {year, month, day};
    }
  }
} */

Date Pars(const std::string& date) {
  std::stringstream is(date);
  int year, month, day;

  is >> year;
  if(is.peek() != '-') {
    throw std::logic_error("Wrong date format: " + date);
  }

  is.ignore(1);

  is >> month;
  if(is.peek() != '-') {
    throw std::logic_error("Wrong date format: " + date);
  }

  is.ignore(1);

  is >> day;

  if(!is.eof()) {
    throw std::logic_error("Wrong date format: " + date);
  }

  return Date(year, month, day);
}

class Database {
public:
  void AddEvent(const Date& date, const std::string& event) {
    database[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const std::string& event) {
    if(database[date].count(event) && database[date].count(event)) {
      database[date].erase(event);
      return true;
    } else {
      return false;
    }
  }
  int DeleteDate(const Date& date) {
    if(!database.count(date)) {
      return 0;
    } 
    else {
      const int count = database[date].size();
      database.erase(date);
      return count;
    }
  }

  std::set<std::string> Find(const Date& date) const {
    if(database.count(date)) return database.at(date);
    else return {};
  }
    
  void Print() const {
    for(const auto& d : database) { // идём по мапе
      if(d.first.GetYear() > 0){ // отсеиваем отрицательные года
        //std::cout << d.first; // выводим год
        for(const auto& e : d.second) { // идём по сету
          std::cout << d.first << " " << e << std::endl; // выводим каждый элемент сета через пробел
        }
      }
    }
  }
private:
  std::map<Date, std::set<std::string>> database;
};

int main() {
  try {
  Database db;
  std::string command;

  while (getline(std::cin, command)) {
    std::string operation;
    std::stringstream is(command);
    is >> operation;
    if(operation == "Add") {
        std::string str_date;
        std::string event;
        is >> str_date >> event;
        Date date = Pars(str_date);
        db.AddEvent(date, event);
    }
    else if(operation == "Find") {
        std::string str_date;
        is >> str_date;
        Date date = Pars(str_date);
        for (const auto& e : db.Find(date)) std::cout << e << std::endl;
    }
    else if(operation == "Del") {
      std::string str_date;
      std::string event;
      is >> str_date;
      Date date = Pars(str_date);
      if(!is.eof()) {
        is >> event;
      }
      if(!event.empty()) {
        if(db.DeleteEvent(date, event)) {
          std::cout << "Deleted successfully" << std::endl;
        }
        else {
          std::cout << "Event not found" << std::endl;
        }
      } else {
        std::cout << "Deleted " << db.DeleteDate(date) << " events" << std::endl;
      }
    }
    else if(operation == "Print") {
      db.Print();
    }
    else if(command.empty()) continue;
    else {
      std::cout << "Unknown command: " << operation << std::endl;
      break;
    }
  }
  } catch (std::logic_error& error) {
    std::cout << error.what() << std::endl;
  }

  return 0;
}