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

		i64 max_so_far = std::numeric_limits<i64>::min();

		for (i = 0; i < ele; ++i) {

			i64 product = 1;

			for (j = i; j < ele; ++j) {

				product *= vec[j];

				max_so_far = std::max(max_so_far, product);
			}
		}

		std::cout << max_so_far << std::endl;
	}

	return 0;
}
