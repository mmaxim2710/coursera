#include <iostream>
#include <string>
#include <queue>

int main() {
    std::string start_num = "";
    int n = 0;
    std::cin >> start_num;
    std::cin >> n;
    int count = 0;
    std::string last = "";
    if(n == 0) {
        std::cout << start_num << std::endl;
    } else {
        std::queue<std::string> operations;
        for(int i = 0; i < n + 1; i++) {
            std::string op;
            std::getline(std::cin, op);
            if((last[0] == '-' || last[0] == '+') && (op[0] == '*' || op[0] == '/')) {
                count++;
                op = ") " + op;
            }
            operations.push(op);
            last = op;
        }

        operations.pop();

        std::string to_ans = "";

        for(int i = 0; i < count; i++) {
            to_ans += "(";
        }
        to_ans += start_num;
        for(int i = 0; i < n; i++) {
            std::string front = operations.front();
            if(front[0] != ')') {
                to_ans += " ";
            }
            to_ans += front;
            operations.pop();
        }

        std::cout << to_ans << std::endl;
    }

    return 0;
}