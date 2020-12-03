#include <iostream>
#include <string>
#include <queue>

int main() {
    std::string start_num = "";
    int n = 0;
    std::cin >> start_num;
    std::cin >> n;
    if(n == 0) {
        std::cout << start_num << std::endl;
    } else {
        std::queue<std::string> operations;
        for(int i = 0; i < n + 1; i++) {
            std::string op;
            std::getline(std::cin, op);
            operations.push(op);
        }

        operations.pop();

        std::string to_ans = "";

        for(int i = 0; i < n; i++) {
            to_ans += "(";
        }
        to_ans += start_num;
        for(int i = 0; i < n; i++) {
            to_ans += ") " + operations.front();
            operations.pop();
        }

        std::cout << to_ans << std::endl;
    }

    return 0;
}