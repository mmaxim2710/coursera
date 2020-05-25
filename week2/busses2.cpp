#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::map<int, std::vector<std::string>> num_busStation;
    int count = 1;

    for(int i = 0; i < n; i++) {
        int num;
        std::cin >> num;
        std::vector<std::string> stations;
        std::string stat;
        bool is_found = false;
        for(int i = 0; i < num; i++) {
            std::cin >> stat;
            stations.push_back(stat);
        }
            
        for(const auto& i : num_busStation) {
            if(i.second == stations) {
                std::cout << "Already exists for " << i.first << std::endl;
                is_found = true;
            }
        }

        if(is_found == false) {
            num_busStation[count] = stations;
            std::cout << "New bus " << count << std::endl;
            count++;
        }
    }
    return 0;
}