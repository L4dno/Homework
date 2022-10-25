#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <iomanip>


int main() {

	long double n = 0;
	long double r = 0;

	std::cin >> n >> r;

	long double R = r * (sin(M_PI / n) / (1 - sin(M_PI / n)));
	std::cout << std::fixed << std::setprecision(6);
	std::cout << R;

	return 0;

}