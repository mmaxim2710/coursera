#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

void all_busses(const map<string, vector<string>>& buses) {
    if (buses.empty()) {
        cout << "No buses" << endl;
    } else {
        for(const auto& i : buses) {
            cout << "Bus " << i.first << ": ";
            for(const auto& stop : i.second) cout << stop << " ";
            cout << endl;
        }
    }                         
}

void busses_for_stop(map<string, vector<string>>& stops, const string& stop) {
	if (stops.count(stop) == 0) cout << "No stop" << endl;
	else {
        for(const auto& i : stops[stop]) cout << i << " ";
        cout << endl;
	}                                
}

void stops_for_bus(map<string, vector<string>>& buses, map<string, vector<string>>& stops, const string& bus) {
	if (buses.count(bus) == 0) cout << "No bus" << endl;
	else {
		for(const string& stop : buses[bus]) {
			cout << "Stop " << stop << ": ";
            if (stops[stop].size() == 1) {
				cout << "no interchange" << endl;
			}
            else {
                for(const auto& other_bus : stops[stop]) {
                	if (bus != other_bus) {
                		cout << other_bus << " ";
                	}
            	}
				cout << endl;
        	}
        }
    }
}

int main() {
    int num_of_commands;
    cin >> num_of_commands;

    map<string, vector<string>> buses;
	map<string, vector<string>> stops_bus;
	string name_of_command;

    for(int i = 0; i < num_of_commands; i++) {
        cin >> name_of_command;

        if (name_of_command == "NEW_BUS") {
            string bus;
            int stop_count;
            cin >> bus;
            cin >> stop_count;

            vector<string>& stops = buses[bus];

            stops.resize(stop_count);

            for(auto& s : stops) {
                cin >> s;
                stops_bus[s].push_back(bus);
            }
        } else if (name_of_command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;
            busses_for_stop(stops_bus, stop);
        } else if (name_of_command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;
            stops_for_bus(buses, stops_bus, bus);
        } else if (name_of_command == "ALL_BUSES") {
            all_busses(buses);
        }
    }
    return 0;
}

