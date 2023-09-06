#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;

size_t count_gap(std::vector<i64> vec, const i64 &target) {

	size_t result = 0;

	std::sort(vec.begin(), vec.end());

	for (size_t i = 0; i < vec.size(); ++i) {

		auto it =
		    std::upper_bound(vec.begin(), vec.begin() + i, vec[i] - target);

		result += vec.begin() - it + i;
	}

	return result;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		i64 target;
		size_t ele, i, j;
		std::cin >> ele >> target;

		std::vector<i64> vec(ele);
		for (auto &i : vec) {
			std::cin >> i;
		}

		std::cout << count_gap(vec, target) << std::endl;
	}

	return 0;
}
