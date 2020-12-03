#include <iostream>
#include <string>

#define GENERATE_LINE2(line) var_##line
#define GENERATE_LINE(line) GENERATE_LINE2(line)
#define UNIQ_ID GENERATE_LINE(__LINE__)


int main() {
    int UNIQ_ID = 5;
    std::string UNIQ_ID = "hello!";

    return 0;
}