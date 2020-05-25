#include <iostream>
#include <string>

int main(int argc, char** argv) {
	std::string str1, str2, str3;

	std::cin >> str1 >> str2 >> str3;

	if (str1 <= str2 && str1 <= str3) {
		std::cout << str1 << std::endl;
	} else if (str2 <= str1 && str2 <= str3) {
		std::cout << str2 << std::endl;
	} else std::cout << str3 << std::endl;

	return 0;
}
