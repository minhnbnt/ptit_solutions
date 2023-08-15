#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

namespace solution {

template <typename T> bool is_prime(T n) {

	static std::vector<bool> vec(2, false);

	if (n >= vec.size()) {

		T prev_size = vec.size();
		vec.resize(n + 1, true);

		T i, j;
		for (i = 0; i <= sqrt(n); ++i) {

			if (!vec[i]) continue;

			T start = std::max(i, prev_size / i) * i;

			for (j = start; j <= n; j += i) {
				vec[j] = false;
			}
		}
	}

	return vec[n];
}

template <typename T> std::pair<T, T> calculate(T target) {

	for (T i = 2; i <= target / 2; ++i) {
		if (!is_prime<T>(i)) continue;
		T j = target - i;
		if (is_prime(j)) return { i, j };
	}

	return { 0, 0 };
}

} // namespace solution

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		using u64 = unsigned long long;

		u64 n;
		std::cin >> n;

		std::pair<u64, u64> result = solution::calculate<u64>(n);

		if (result != std::pair<u64, u64>({ 0, 0 })) {
			std::cout << result.first << ' ' << result.second;
		}
		std::cout << std::endl;
	}

	return 0;
}
