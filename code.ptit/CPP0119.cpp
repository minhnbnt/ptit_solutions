#include <iostream>
#include <vector>

using u64 = unsigned long long;

u64 gcd(u64 a, u64 b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

u64 lcm(u64 a, u64 b) {
	return a * b / gcd(a, b);
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		static std::vector<u64> vec;

		unsigned n, i;
		std::cin >> n;

		size_t prev_size = vec.size();
		if (n >= prev_size) {

			vec.resize(n + 1, 1);

			for (i = prev_size; i <= n; ++i) {

				if (i == 0) continue;

				vec[i] = vec[i - 1];

				if (vec[i] % i != 0) vec[i] = lcm(vec[i], i);
			}
		}

		std::cout << vec[n] << std::endl;
	}

	return 0;
}
