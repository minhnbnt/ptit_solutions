#include <algorithm>
#include <iostream>
#include <string>

using u64 = long long;

const int MOD = 1e9 + 7;

u64 bin_pow(u64 base, u64 exponent) {

	if (exponent == 0) {
		return 1;
	}

	if (exponent % 2 == 0) {
		const u64 square_rooted = bin_pow(base, exponent / 2);
		return square_rooted * square_rooted % MOD;
	}

	return base * bin_pow(base, exponent - 1) % MOD;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		std::string num;
		std::cin >> num;

		const std::string reversed(num.rbegin(), num.rend());

		const u64 result = bin_pow(std::stoull(num), std::stoull(reversed));
		std::cout << result << std::endl;
	}

	return 0;
}
