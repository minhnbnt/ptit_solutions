#include <algorithm>
#include <cmath>
#include <iostream>

int main(void) {

	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 arr[3];
		for (u64 &x : arr) {
			std::cin >> x;
		}

		int digits;
		std::cin >> digits;

		const u64 min = pow(10, digits - 1), max = min * 10 - 1;

		u64 base = 1;
		for (u64 &x : arr)
			if (base % x != 0) {
				base *= x / std::__gcd(base, x);
			}

		const u64 result = (((min - 1) / base) + 1) * base;

		if (result > max) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
