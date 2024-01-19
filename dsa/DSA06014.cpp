#include <complex>
#include <iostream>
#include <vector>

bool is_prime(unsigned x) {

	static std::vector<bool> vec(2, false);

	if (vec.size() > x) {
		return vec[x];
	}

	unsigned i, j;
	const unsigned prev_size = vec.size();

	vec.resize(x + 1, true);
	for (i = 2; i <= std::sqrt(x); i++) {

		if (!vec[i]) {
			continue;
		}

		const unsigned start = std::max(i, prev_size / i) * i;

		for (j = start; j <= x; j += i) {
			vec[j] = false;
		}
	}

	return vec[x];
}

std::pair<unsigned, unsigned> has_pair_primes(unsigned sum) {

	for (unsigned i = 2; i < sum; i++) {

		if (!is_prime(i)) {
			continue;
		}

		const unsigned other = sum - i;

		if (!is_prime(other)) {
			continue;
		}

		return std::make_pair(i, other);
	}

	return std::make_pair(0, 0);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		unsigned sum;
		std::cin >> sum;

		const auto result = has_pair_primes(sum);
		if (result.first != 0) {
			std::cout << result.first << ' ' << result.second;
		} else {
			std::cout << -1;
		}

		std::cout << std::endl;
	}

	return 0;
}
