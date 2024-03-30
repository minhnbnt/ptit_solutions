#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned i, rank;
	std::cin >> rank;

	std::vector<std::vector<bool>> matrix(rank);
	for (std::vector<bool> &row : matrix) {
		row.resize(rank, false);
		for (i = 0; i < rank; i++) {

			int value;
			std::cin >> value;

			row[i] = value == 1;
		}
	}

	for (std::vector<bool> &row : matrix) {

		for (i = 0; i < rank; i++) {
			if (!row[i]) continue;
			std::cout << i + 1 << ' ';
		}

		std::cout.put(10);
	}

	std::cout.flush();

	return 0;
}
