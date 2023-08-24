#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

bool is_prime(unsigned x) {
	for (unsigned i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0) return false;
	}
	return x > 1;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 x, i, j;
		std::cin >> x;

		std::vector<bool> vec(x, true);
		vec[0] = vec[1] = false;
		for (i = 2; i <= sqrt(x); ++i) {

			unsigned count = 0;
			while (x % i == 0) {
				x /= i;
				++count;
			}

			if (count == 0) continue;
			for (j = i; j < vec.size(); j += i) {
				vec[j] = false;
			}
		}
		if (x > 1) {
			for (j = x; j < vec.size(); j += x) {
				vec[j] = false;
			}
		}

		unsigned count = 1;
		for (i = 1; i < vec.size(); ++i) {
			if (vec[i]) ++count;
		}
		std::cout << is_prime(count) << std::endl;
	}

	return 0;
}
