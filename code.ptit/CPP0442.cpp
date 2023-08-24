#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	using u64 = unsigned long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 ele, target;
		std::cin >> ele >> target;

		std::vector<u64> vec(ele);
		for (u64 &x : vec) {
			std::cin >> x;
		}

		if (!std::is_sorted(vec.begin(), vec.end())) {
			std::sort(vec.begin(), vec.end());
		}

		bool result = std::binary_search(vec.begin(), vec.end(), target);
		std::cout << (result ? 1 : -1) << std::endl;
	}

	return 0;
}
