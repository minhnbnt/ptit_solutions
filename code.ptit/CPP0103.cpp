#include <iomanip>
#include <iostream>

int main(void) {

	unsigned long n;
	std::cin >> n;

	double sum = 0;

	while (n > 0) {
		sum += 1.0 / n;
		--n;
	}

	std::cout << std::fixed << std::setprecision(4) << sum << std::endl;

	return 0;
}
