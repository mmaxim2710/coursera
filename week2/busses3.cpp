#include <iostream>
#include <string>
#include <map>
#include <set>

int main() {
    int num_of_commands;
    std::cin >> num_of_commands;
    std::map<int, std::set<std::string>> bus;
    int count = 1;

    for(int i = 0; i < num_of_commands; i++) {
        std::set<std::string> stations;
        int num_of_stations;
        std::cin >> num_of_stations;
        for(int j = 0; j < num_of_stations; j++) {
            std::string stat;
            std::cin >> stat;
            stations.insert(stat);
        }

        bool is_found = false;
        int founded_num;

        for(auto b : bus) {
            if(b.second == stations) {
                is_found = true;
                founded_num = b.first;
            }
        }
        if(is_found == true) {
            std::cout << "Already exists for " << founded_num << std::endl;
        }
        else if(is_found == false) {
            bus[count] = stations;
            std::cout << "New bus " << count << std::endl;
            count++;
        }
        
        //bus[count] = stations;
        //count++;
    }
    return 0;
}