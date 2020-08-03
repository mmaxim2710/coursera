#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

struct FirstLastName {
    std::string first_name;
    std::string last_name;
};

class Person {
    private:
        std::map<int, FirstLastName> history_of_name;
    public:
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

        std::string GetFullName(int year) {
            std::string first_name_to_output = "";
            std::string last_name_to_output = "";
            
            if(history_of_name.size() == 0) {
                return "Incognito";
            } else {
                for(const auto& i : history_of_name) {
                    if(year < i.first) {
                        return "Incognito";
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

        std::string GetFullNameWithHistory(int year) {
        if (history_of_name.size() == 0) {
            return "Incognito";
        } else {
            for (const auto& i : history_of_name) {
                if (year < i.first) {
                    return "Incognito";
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

void TestGetFullName() {
    {
        Person person;
        AssertEqual(person.GetFullName(1959), "Incognito", "empty person");
    }
    
    {
        Person person;
        person.ChangeFirstName(1960, "Maxim");
        AssertEqual(person.GetFullName(1960), "Maxim with unknown last name", "Name with empty last name");
    }

    {
        Person person;
        person.ChangeFirstName(1960, "Maxim");
        person.ChangeLastName(1961, "Zherlygin");
        AssertEqual(person.GetFullName(1960), "Maxim with unknown last name", "Calling func at 1960 with name(1960) and lastname(1961)");
    }

    {
        Person person;
        person.ChangeFirstName(1960, "Maxim");
        person.ChangeLastName(1960, "Zherlygin");
        AssertEqual(person.GetFullName(1960), "Maxim Zherlygin", "Name and last name");
    }

    {
        Person person;
        person.ChangeFirstName(1960, "Maxim");
        person.ChangeLastName(1960, "Zherlygin");
        AssertEqual(person.GetFullName(1959), "Incognito", "Not empty full name, but early date (name = 1960, call func = 1959)");
    }

    {
        Person person;
        person.ChangeFirstName(1960, "Maxim");
        person.ChangeLastName(1960, "Zherlygin");
        AssertEqual(person.GetFullName(1961), "Maxim Zherlygin", "name = 1960, call func = 1961");
    }

    {
        Person person;
        person.ChangeFirstName(1960, "Maxim");
        person.ChangeLastName(1961, "Zherlygin");
        person.ChangeFirstName(1970, "Sergey");
        AssertEqual(person.GetFullName(1965), "Maxim Zherlygin", "full name(1960, 1961), call func(1965)");
        AssertEqual(person.GetFullName(1971), "Sergey Zherlygin", "change name after naming");
    }
}

void TestChangeFirstName() {
    {
        Person person;
        person.ChangeFirstName(1960, "Maxim");
        AssertEqual(person.GetFullName(1959), "Incognito", "early date calling func");
        AssertEqual(person.GetFullName(1961), "Maxim with unknown last name", "empty last name");
    }

    {
        Person person;
        person.ChangeFirstName(1960, "Maxim");
        person.ChangeFirstName(1965, "Denis");
        person.ChangeFirstName(1970, "Sergey");
        AssertEqual(person.GetFullName(1959), "Incognito", "empty");
        AssertEqual(person.GetFullName(1961), "Maxim with unknown last name", "add name");
        AssertEqual(person.GetFullName(1966), "Denis with unknown last name", "change name");
        AssertEqual(person.GetFullName(1971), "Sergey with unknown last name", "change name");
    }
}

void TestChangeLastName() {
    {
        Person person;
        person.ChangeLastName(1960, "Zherlygin");
        AssertEqual(person.GetFullName(1959), "Incognito", "early date calling func");
        AssertEqual(person.GetFullName(1961), "Zherlygin with unknown first name", "empty first name");
    }

    {
        Person person;
        person.ChangeLastName(1960, "Zherlygin");
        person.ChangeLastName(1970, "Mironov");
        person.ChangeLastName(1980, "C");
        AssertEqual(person.GetFullName(1959), "Incognito", "empty");
        AssertEqual(person.GetFullName(1961), "Zherlygin with unknown first name", "change last name");
        AssertEqual(person.GetFullName(1971), "Mironov with unknown first name", "change last name");
        AssertEqual(person.GetFullName(1981), "C with unknown first name", "change last name");
    }
}

int main() {
  TestRunner runner;
  runner.RunTest(TestChangeFirstName, "TestChangeFirstName");
  runner.RunTest(TestChangeLastName, "TestChangeLastName");
  runner.RunTest(TestGetFullName, "TestGetFullName");
  return 0;
}