#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

void PrintVector(std::vector<std::string> input) {
    for(auto i : input) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void PrintError() {
    std::cout << "no interchange" << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    std::map<std::string, std::vector<std::string>> bus_stops;

    for(int i = 0; i < n; i++) {
        std::string name_of_command;
        std::cin >> name_of_command;
        if(name_of_command == "NEW_BUS") {
            std::string bus;
            std::string name_of_stop;
            int count;
            std::cin >> bus >> count;
            std::vector<std::string> stops;
            for(int i = 0; i < count; i++) {
                std::cin >> name_of_stop;
                stops.push_back(name_of_stop);
                bus_stops[bus] = stops;
            }
            /*for(const auto& i : bus_stops) {
                std::cout << "Bus " << i.first << " has routes ";
                PrintVector(i.second);
            }*/
        } else if(name_of_command == "BUSES_FOR_STOP") {
            std::string name_of_stop;
            std::cin >> name_of_stop;

            std::vector<std::string> to_input;

            bool is_found = false;

            for(const auto& i : bus_stops) {
                for(const auto& v : i.second) {
                    if(v == name_of_stop) {
                        is_found = true;
                        to_input.push_back(i.first);
                    }
                }
            }
            if(is_found == false) {
                std::cout << "No stop" << std::endl;
            } else if(is_found == true) {
                for(const auto& i : to_input) {
                    std::cout << i << " ";
                }
                std::cout << std::endl;
            }
        } else if(name_of_command == "STOPS_FOR_BUS") {
            if(bus_stops.empty()) {
                std::cout << "No bus" << std::endl;
            } else {
            std::string bus;
            std::cin >> bus;
            std::vector<std::string> stops_of_bus;
            //std::vector<std::string> bus_to_change;
            std::map<std::string, std::vector<std::string>> stop_buses;
            bool is_found = false;
            for(const auto& i : bus_stops) {
                if(i.first == bus) stops_of_bus = i.second;
            }

            //std::reverse(std::begin(stops_of_bus), std::end(stops_of_bus));

            for(const auto& b : bus_stops) {
                for(const auto& v : b.second) {
                    for(const auto& k : stops_of_bus) {
                        if(v == k) {
                            is_found = true;
                            stop_buses[k].push_back(b.first);
                            break;
                        }
                    }
                }
            }

            for(const auto& i : stop_buses) {
                std::reverse(std::begin(i.second), std::end(i.second));
                std::cout << "Stop " << i.first << ": ";
                if(is_found == true)
                    PrintVector(i.second);
                else if(is_found == false)
                    PrintError();
            }
            }
        }
    }
    return 0;
}