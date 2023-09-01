#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i, j;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		i64 result = std::numeric_limits<i64>::min();

		for (i = 0; i < ele; ++i)
			for (j = i + 1; j < ele; ++j) {

				if (vec[i] >= vec[j]) {
					continue;
				}

				i64 gap = vec[j] - vec[i];
				if (gap > result) {
					result = gap;
				}
			}

		if (result == std::numeric_limits<i64>::min()) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
