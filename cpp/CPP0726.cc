#include <iostream>

int main(void) {

	using u128 = __uint128_t;
	using u64 = unsigned long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		u64 a, b, c;
		std::cin >> a >> b >> c;

		const u64 result = static_cast<u128>(a) * b % c;
		std::cout << result << std::endl;
	}

	return 0;
}
