#include <algorithm>
#include <iostream>
#include <vector>

size_t count_pair(std::vector<int> &vec, int target_diff) {

	std::sort(vec.begin(), vec.end());

	size_t result = 0;

	for (auto it = vec.begin(); it < vec.end(); it++) {
		auto it_start = std::upper_bound(vec.begin(), it, (*it) - target_diff);
		result += std::distance(it_start, it);
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		unsigned target_diff;
		std::cin >> size >> target_diff;

		std::vector<int> vec(size);
		for (int &element : vec) {
			std::cin >> element;
		}

		std::cout << count_pair(vec, target_diff) << std::endl;
	}

	return 0;
}
