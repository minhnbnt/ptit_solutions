#include <algorithm>
#include <complex>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		int target;
		size_t size;
		std::cin >> size >> target;

		std::vector<int> vec(size);
		for (int &element : vec) {
			std::cin >> element;
		}

		std::stable_sort(vec.begin(), vec.end(), [target](int a, int b) {
			const int a_diff = std::abs(a - target);
			const int b_diff = std::abs(b - target);

			return a_diff < b_diff;
		});

		for (int element : vec) {
			std::cout << element << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
