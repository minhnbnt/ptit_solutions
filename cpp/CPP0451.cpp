#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		/* for some reasons, this only works with int,
		   but not size_t or unsigned long long (which i loved) */

		int ele;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		int target, nearest;
		std::cin >> nearest >> target;

		const int index = std::lower_bound(vec.begin(), vec.end(), target) - vec.begin();
		int left = index - nearest / 2, right = index;

		if (vec[index] == target) ++right;

		for (int i = 0; i < nearest / 2; ++i) {
			std::cout << vec[left + i] << ' ';
		}
		for (int i = 0; i < nearest / 2; ++i) {
			std::cout << vec[right + i] << ' ';
		}

		std::cout << std::endl;
	}

	return 0;
}
