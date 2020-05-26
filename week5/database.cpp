#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>

class Date {
public:
  Date() : day(0), month(0), year(0) {
  }
  Date(const int& day, const int& month, const int& year) {
    if(month < 1 && month > 12) {
      throw std::logic_error("Month value is invalid: ");
    }
    else if(day < 1 && day > 31) {
      throw std::logic_error("Day value is invalid: ");
    }
    else {
      this->day = day;
      this->month = month;
      this->year = year;
    }
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
  if(lhs.GetYear() < rhs.GetYear()) {
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
  }
}

bool operator==(const Date& lhs, const Date& rhs) {
  return (lhs.GetDay() == rhs.GetDay()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetYear() == rhs.GetYear());
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
  os << std::setw(4) << std::setfill('0') << date.GetYear() << "-" << std::setw(2) << std::setfill('0') << date.GetMonth() << "-" << std::setw(2) << std::setfill('0') << date.GetDay();
  return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
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
}

class Database {
public:
  void AddEvent(const Date& date, const std::string& event) {
    if(!database.count(date)) {
      if(!database[date].count(event)) {
        database[date].insert(event);
      }
    }
  }
  bool DeleteEvent(const Date& date, const std::string& event) {
    if(database[date].count(event)) {
      database[date].erase(event);
      std::cout << "Deleted successfully" << std::endl;
    } else {
      std::cout << "Event not found" << std::endl;
    }
  }
  int DeleteDate(const Date& date) {
    int count = database[date].size();
    database[date].clear();
    std::cout << "Deleted " << count << " events" << std::endl;
  }

  void Find(const Date& date) const {
    for(const auto& d : database) {//      идём по map'е в поисках нужной даты
      if(d.first == date) { //             ищем нужную дату
        for(const auto& e : d.second) { // идём по контеёнеру set
          std::cout << e << std::endl; //  и выводим содержимое
        }
        return;
      }
    }
  }
    
  void Print() const {
    for(const auto& d : database) { // идём по мапе
      if(d.first.GetYear() > 0){ // отсеиваем отрицательные года
        std::cout << d.first; // выводим год
        for(const auto& e : d.second) { // идём по сету
          std::cout << e << " "; // выводим каждый элемент сета через пробел
        }
        std::cout << std::endl; // в конце ставим перевод строки
      }
    }
  }
private:
  std::map<Date, std::set<std::string>> database;
};

int main() {
  Database db;

  std::string command;
  while (getline(std::cin, command)) {
    if(command == "Add") {
      try{
        Date data;
        std::string event;
        std::cin >> data >> event;
        db.AddEvent(data, event);
      } catch (std::logic_error& error) {
        std::cout << error.what();
      }
    }
    else if(command == "Find") {
      try {
        Date date;
        std::cin >> date;
        db.Find(date);
      } catch (std::logic_error& error) {
        std::cout << error.what();
      }
    }
  }

  return 0;
}