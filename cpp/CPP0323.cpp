#include <algorithm>
#include <iostream>

using u64 = unsigned long long;

u64 module(std::string s, u64 mod) {

	std::reverse(s.begin(), s.end());

	u64 result = 0, base = 1;

	for (const char &c : s) {

		const unsigned short digit = c - '0';

		result += (base * digit) % mod;
		result %= mod;

		base = (base * 10) % mod;
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 mod;
		std::string num;
		std::cin >> std::ws >> num >> mod;

		std::cout << module(num, mod) << std::endl;
	}

	return 0;
}
