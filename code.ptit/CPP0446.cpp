#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &i : vec) {
			std::cin >> i;
		}

		i64 result = std::numeric_limits<i64>::max();

		unsigned i, j;
		for (i = 0; i < ele; ++i)
			for (j = i + 1; j < ele; ++j) {

				i64 sum = vec[i] + vec[j];

				if (std::abs(sum) < std::abs(result)) {
					result = sum;
				}
			}

		std::cout << result << std::endl;
	}

	return 0;
}
