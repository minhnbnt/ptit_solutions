#include <iostream>
#include <vector>

size_t balance_pos(const std::vector<int> &vec) {

	using i64 = long long;

	i64 sum_of_vec = 0;
	for (const int &x : vec) {
		sum_of_vec += x;
	}

	i64 sum_of_left = 0;
	i64 sum_of_remaining = sum_of_vec;

	for (size_t i = 0; i < vec.size(); ++i) {

		if (sum_of_left == sum_of_remaining - vec.at(i)) {
			return i;
		}

		sum_of_left += vec.at(i);
		sum_of_remaining -= vec.at(i);
	}

	return -1;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		size_t pos = balance_pos(vec);
		if (pos == size_t(-1)) {
			std::cout << -1 << std::endl;
			continue;
		}
		std::cout << pos + 1 << std::endl;
	}

	return 0;
}
