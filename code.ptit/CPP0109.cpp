#include <complex>
#include <iostream>

bool balance_of_oddeven(unsigned long num) {

	unsigned odd = 0, even = 0;

	while (num > 0) {
		if (num % 2) ++odd;
		else ++even;
		num /= 10;
	}

	return odd == even;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned int n;
	std::cin >> n;

	const unsigned long start = pow(10, n - 1), end = start * 10;

	int count = 0;

	for (unsigned long i = start; i < end; i++) {

		if (balance_of_oddeven(i)) {
			std::cout << i << ' ';
			++count;
		}

		if (count == 10) {
			count = 0;
			std::cout << std::endl;
		}
	}

	if (count != 0) std::cout << std::endl;

	return 0;
}
