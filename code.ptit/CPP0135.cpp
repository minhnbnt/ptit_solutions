#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		static std::vector<bool> vec(2, false);

		u64 _n, i, j;
		std::cin >> _n;

		u64 n = sqrt(_n);

		if (n >= vec.size()) {

			u64 prev_size = vec.size();
			vec.resize(n + 1, true);

			for (i = 2; i < sqrt(n); i++) {

				if (!vec[i]) continue;

				u64 start = std::max(i, prev_size / i) * i;
				for (j = start; j <= n; j += i) {
					vec[j] = false;
				}
			}
		}

		for (i = 0; i <= n; ++i) {
			if (!vec[i]) continue;
			std::cout << i * i << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
