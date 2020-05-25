#include <iostream>

int main(int argc, char** argv) {
	unsigned int A, B = 0;
	std::cin >> A >> B;

	if (B == 0)
		std::cout << "Impossible" << std::endl;
	else {
		int sum = A / B;
		std::cout << sum << std::endl;
	}
	return 0;
}
