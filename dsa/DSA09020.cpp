#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned i, rank;
	std::cin >> rank;
	std::vector<std::vector<unsigned>> adj_list(rank);

	for (i = 0; i < rank; i++) {

		std::string line;
		std::getline(std::cin >> std::ws, line);
		std::istringstream iss(line);

		unsigned value;
		while (iss >> value) {
			adj_list[i].push_back(value - 1);
			adj_list[value - 1].push_back(i);
		}
	}

	std::vector<std::vector<bool>> matrix(rank);
	for (std::vector<bool> &row : matrix) {
		row.resize(rank, false);
	}

	for (i = 0; i < rank; i++) {
		for (int j : adj_list[i]) {
			matrix[i][j] = true;
		}
	}

	for (std::vector<bool> &row : matrix) {

		for (bool b : row) {
			std::cout << b << ' ';
		}

		std::cout.put('\n');
	}

	std::cout.flush();

	return 0;
}
