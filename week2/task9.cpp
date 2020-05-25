#include <iostream>
#include <vector>
#include <string>

int absolute(int i) {
    if(i == 0) return 0;
    else if(i > 0) return i;
    else return -1 * i;
}

void worry(std::vector<bool>& queue, int i) { // true - норм, false - бесп.
    queue[i] = false;
}

void quiet(std::vector<bool>& queue, int i) {
    queue[i] = true;
}

void come(std::vector<bool>& queue, int arg) {
    if(arg > 0) {
        for(int i = 0; i < arg; i++) {
            queue.push_back(true);
        }
    } else if(arg < 0) {
        arg = absolute(arg);
        for(int i = 0; i < arg; i++) {
            queue.pop_back();
        }
    }
}

void worry_count(const std::vector<bool>& queue) {
    int count = 0;
    for(int i = 0; i < queue.size(); i++) {
        if(queue[i] == false) count++;
    }
    std::cout << count << std::endl;
}

int main() {
    int num_of_operations;
    std::cin >> num_of_operations;
    std::vector<bool> queue;
    std::string command;
    int arg;

    for(int i = 0; i < num_of_operations; i++) {
        std::cin >> command;
        if(command == "WORRY") {
            std::cin >> arg;
            worry(queue, arg);
        } else if(command == "QUIET") {
            std::cin >> arg;
            quiet(queue, arg);
        } else if(command == "COME") {
            std::cin >> arg;
            come(queue, arg);
        } else if(command == "WORRY_COUNT") {
            worry_count(queue);
        }
    }
    return 0;
}  