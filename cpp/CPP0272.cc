#include <algorithm>
#include <iostream>
#include <vector>

using u64 = unsigned long long;
static const long mod = 1e9 + 7;

unsigned get_gcd(const std::vector<unsigned> &vec) {

	unsigned result = vec[0];
	for (size_t i = 0; i < vec.size(); ++i) {
		result = std::__gcd(result, vec[i]);
	}

	return result;
}

u64 get_product(const std::vector<unsigned> &vec) {

	u64 result = 1;
	for (const unsigned &x : vec) {
		result *= x;
		result %= mod;
	}

	return result;
}

u64 bin_pow(u64 base, unsigned exp) {

	u64 result = 1;

	while (exp > 0) {

		if (exp % 2 == 1) {
			result *= base;
			result %= mod;
		}

		base = (base * base) % mod;
		exp /= 2;
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<unsigned> vec(ele);
		for (unsigned &x : vec) {
			std::cin >> x;
		}

		const unsigned gcd = get_gcd(vec);
		const u64 base = get_product(vec);

		std::cout << bin_pow(base, gcd) << std::endl;
	}

	return 0;
}
