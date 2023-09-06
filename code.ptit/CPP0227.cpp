#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned rank, i;
		std::cin >> rank;

		std::vector<std::vector<int>> vec(rank);
		for (i = 0; i < rank; ++i) {

			vec[i].resize(rank);

			for (int &x : vec[i]) {
				std::cin >> x;
			}

			if (i % 2 == 1) {
				std::reverse(vec[i].begin(), vec[i].end());
			}
		}

		for (const std::vector<int> &row : vec)
			for (const int &x : row) {
				std::cout << x << ' ';
			}
		std::cout << std::endl;
	}

	return 0;
}
