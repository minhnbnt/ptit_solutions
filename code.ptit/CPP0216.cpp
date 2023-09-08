#include <algorithm>
#include <iostream>
#include <vector>

bool is_mountain(const std::vector<int>::iterator &it1,
                 const std::vector<int>::iterator &it2) {

	const std::vector<int>::iterator it = std::is_sorted_until(it1, it2);

	return std::is_sorted_until(it, it2, std::greater<int>()) == it2;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		size_t left, right;
		std::cin >> left >> right;

		bool result = is_mountain(vec.begin() + left, vec.begin() + right + 1);

		std::cout << (result ? "Yes" : "No") << std::endl;
	}

	return 0;
}
