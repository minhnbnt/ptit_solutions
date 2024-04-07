#include <algorithm>
#include <iostream>
#include <vector>

bool is_valid(const std::vector<int> &vec) {

	for (size_t i = 1; i < vec.size(); i++) {
		if (std::abs(vec[i] - vec[i - 1]) < 2) {
			return false;
		}
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int i, size;
		std::cin >> size;

		std::vector<int> vec(size);
		for (i = 0; i < size; i++) {
			vec[i] = i + 1;
		}

		do {

			if (!is_valid(vec)) {
				continue;
			}

			for (int x : vec) {
				std::cout << x;
			}

			std::cout.put('\n');

		} while (std::next_permutation(vec.begin(), vec.end()));

		std::cout.flush();
	}

	return 0;
}
