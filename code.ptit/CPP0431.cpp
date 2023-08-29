#include <algorithm>
#include <iostream>
#include <vector>

using i64 = long long;
using u64 = unsigned long long;

u64 count_gap(std::vector<i64> vec, i64 target) {

	u64 result = 0;

	std::sort(vec.begin(), vec.end());
	for (size_t i = 0; i < vec.size(); ++i) {
		i64 &x = vec[i];

		size_t pos = i;
		while (pos >= 0) {
			--pos;
		}
	}

	return result;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		i64 target;
		size_t ele;
		std::cin >> ele >> target;

		std::vector<i64> vec(ele);
		for (auto &i : vec) {
			std::cin >> i;
		}

		std::cout << count_gap(vec, target) << std::endl;
	}

	return 0;
}
