#include <complex>
#include <iostream>

using u64 = unsigned long long;

bool is_sphenic(u64 x) {
	int remaining = 3;

	for (u64 i = 2; i <= sqrt(x); ++i) {
		unsigned count = 0;
		while (x % i == 0) {
			x /= i;

			--remaining, ++count;
			if (count > 1) return false;
			if (remaining == 0) {
				break;
			}
		}
	}

	if (x > 1) --remaining;

	return remaining == 0;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 x;
		std::cin >> x;

		std::cout << is_sphenic(x) << std::endl;
	}

	return 0;
}
