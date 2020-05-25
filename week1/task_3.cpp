#include <iostream>
#include <cmath>

int main(int argc, char** argv) {
	double a, b, c = 0;
	std::cin >> a >> b >> c;

	if((pow(b, 2) - 4 * a * c) < 0) return 0;

	else if(a == 0 && b == 0) return 0;

	else if ((pow(b, 2) - 4 * a * c) > 0 && a != 0) {
		double D = pow(b, 2) - 4 * a * c;
		double x1 = ((-1) * b + sqrt(D))/(2 * a);
		double x2 = ((-1) * b - sqrt(D))/(2 * a);
		std::cout << x1 << " " << x2 << std::endl;
	}

	else if ((pow(b, 2) - 4 * a * c) == 0 && a != 0) {
		double x = ((-1) * b) / (2 * a);
		std::cout << x << std::endl;
	}

	else if (a == 0) {
		double x3 = ((-1) * c / b);
		std::cout << x3 << std::endl;
	}
	return 0;
}
