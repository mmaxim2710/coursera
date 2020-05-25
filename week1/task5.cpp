#include <iostream>

int main(int argc, char** argv) {
	double N, A, B, X, Y = 0;
	std::cin >> N >> A >> B >> X >> Y;

	if(N > B) {
		N *= 1 - Y / 100.0;
	}
	else if(N > A) {
		N *= 1 - X / 100.0;
	}
	std::cout << N << std::endl;

	return 0;
}
