#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t ele;
		int target;
		std::cin >> ele >> target;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		auto it = std::find(vec.cbegin(), vec.cend(), target);
		std::cout << std::distance(vec.cbegin(), it) + 1 << std::endl;
	}

	return 0;
}
