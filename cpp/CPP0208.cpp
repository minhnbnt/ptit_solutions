#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, target;
		std::cin >> ele >> target;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		std::sort(vec.begin(), vec.end());

		std::cout << vec[target - 1] << std::endl;
	}

	return 0;
}
