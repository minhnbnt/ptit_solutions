#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

size_t result_with_current(unsigned current, const std::vector<unsigned> &vec,
                           const std::array<size_t, 5> less_than_5) {

	if (current == 0) return 0;
	if (current == 1) return less_than_5[0];

	auto it = std::upper_bound(vec.begin(), vec.end(), current);

	size_t result = std::distance(it, vec.end());
	result += less_than_5[0] + less_than_5[1];

	if (current == 2) {
		result -= less_than_5[3] + less_than_5[4];
	} else if (current == 3) {
		result += less_than_5[2];
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size1, size2;
		std::cin >> size1 >> size2;

		std::vector<unsigned> vec1(size1), vec2(size2);
		std::array<size_t, 5> less_than_5;

		for (unsigned &x : vec1) {
			std::cin >> x;
		}

		less_than_5.fill(0);

		for (unsigned &x : vec2) {

			std::cin >> x;

			if (x < less_than_5.size()) {
				less_than_5[x] += 1;
			}
		}

		std::sort(vec2.begin(), vec2.end());

		size_t result = 0;

		for (const unsigned element : vec1) {
			result += result_with_current(element, vec2, less_than_5);
		}

		std::cout << result << std::endl;
	}

	return 0;
}
