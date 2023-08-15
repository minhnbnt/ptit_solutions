#include <iostream>
#include <vector>

using u64 = unsigned long long;

u64 get_fibonacci(unsigned n) {

	static std::vector<u64> fibs = { 0, 1, 1 };

	if (n >= fibs.size()) {
		fibs.resize(n + 1, 0);
	}

	if (fibs[n] == 0 && n > 0) {
		fibs[n] = get_fibonacci(n - 1) + get_fibonacci(n - 2);
	}

	return fibs[n];
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned n;
		std::cin >> n;

		std::cout << get_fibonacci(n) << std::endl;
	}

	return 0;
}
