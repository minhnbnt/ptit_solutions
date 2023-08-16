#include <iostream>
#include <vector>

using u64 = unsigned long long;

u64 get_mod_fib(unsigned n) {

	static const u64 mod = 1e9 + 7;
	static std::vector<u64> fibs = { 0, 1 };

	if (n > fibs.size()) {
		fibs.resize(n + 1, 0);
	}

	if (fibs[n] == 0 && n > 1) {
		fibs[n] = (get_mod_fib(n - 1) + get_mod_fib(n - 2)) % mod;
	}

	return fibs[n];
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned n;
		std::cin >> n;

		std::cout << get_mod_fib(n) << std::endl;
	}

	return 0;
}
