#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

class solution {

	static bool is_prime(u64 num) {

		static std::vector<bool> vec(2, false);

		if (num >= vec.size()) {

			size_t prev_size = vec.size();
			vec.resize(num + 1, true);

			static u64 i, j;
			for (i = 2; i <= num; ++i) {

				if (!vec[i]) continue;

				u64 start = std::max(i * i, (prev_size / i) * i);
				for (j = start; j <= num; j += i) {
					vec[j] = false;
				}
			}
		}

		return vec[num];
	}
public:
	static std::pair<u64, u64> calculate(u64 target) {

		for (u64 i = 2; i <= target / 2; i++) {
			if (!is_prime(i)) continue;
			u64 j = target - i;
			if (is_prime(j)) return { i, j };
		}

		return { 0, 0 };
	}
};

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 n;
		std::cin >> n;

		std::pair<u64, u64> result = solution::calculate(n);

		if (result != std::pair<u64, u64>({ 0, 0 })) {
			std::cout << result.first << " " << result.second;
		} else std::cout << -1;

		std::cout << std::endl;
	}

	return 0;
}
