#include <iostream>
#include <vector>

int main(int argc, char** argv) {
    int number;
    int remaind;
    std::cin >> number;

    std::vector<int> v_number;
    if(number == 1) std::cout << "1" << std::endl;
    if(number == 0) std::cout << "0" << std::endl;
    else {
        while(number > 1) {
            remaind = number % 2;
            v_number.push_back(remaind);
            if(number / 2 == 1) v_number.push_back(1);
            number /= 2;
        }

        for(int i = v_number.size() - 1; i >= 0; i--) {
            std::cout << v_number[i];
        }
        std::cout << std::endl;
    }

    return 0;

}

https://vk.com/away.php?to=https%3A%2F%2Finstagram.com%2Fa%2Fr%2F%3Feffect_id%3D914696838967884%26ch%3DYmM4ZDU1NjgzMmM4Y2VjYjg1ZTliNjY0MTE4ZGVjYTk%253D&cc_key=
https://vk.com/away.php?to=https%3A%2F%2Finstagram.com%2Fa%2Fr%2F%3Feffect_id%3D914696838967884%26ch%3DYmM4ZDU1NjgzMmM4Y2VjYjg1ZTliNjY0MTE4ZGVjYTk%253D&cc_key=