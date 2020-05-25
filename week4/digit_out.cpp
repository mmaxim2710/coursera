// #include <iostream>
// #include <fstream>
// #include <iomanip>

// int main(int argc, char** argv) {
//     std::ifstream is("input.txt");
//     std::string value;
//     while(getline(is, value)) {
//         std::cout << std::fixed << std::setprecision(3);
//         std::cout << std::atof(value.c_str()) << std::endl;
//     }
//     return 0;
// }

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    ifstream input("input.txt");

    double a;

    cout << fixed << setprecision(3);

    while (input >> a) {
        cout << a << endl;
    }

    return 0;
}