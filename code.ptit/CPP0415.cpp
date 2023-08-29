#include <iostream>
#include <limits>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t eleA, eleB, i;
		std::cin >> eleA >> eleB;

		i64 maxA = std::numeric_limits<i64>::min(),
		    minB = std::numeric_limits<i64>::max();

		for (i = 0; i < eleA; ++i) {

			i64 x;
			std::cin >> x;

			if (x > maxA) maxA = x;
		}

		for (i = 0; i < eleB; ++i) {

			i64 x;
			std::cin >> x;

			if (x < minB) minB = x;
		}

		std::cout << maxA * minB << std::endl;
	}

	return 0;
}
