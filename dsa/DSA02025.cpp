#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

size_t count_duplicates(const std::string &s1, const std::string &s2) {

	size_t counter = 0;

	for (char c1 : s1) {
		for (char c2 : s2) {
			if (c1 == c2) {
				counter++;
			}
		}
	}

	return counter;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int size, i, j;
	std::cin >> size;

	std::vector<std::string> vec(size);
	for (std::string &s : vec) {
		std::cin >> s;
	}

	std::vector<std::vector<size_t>> dups(size);
	for (i = 0; i < size; i++) {

		dups[i].resize(size);

		for (j = 0; j < size; j++) {
			dups[i][j] = count_duplicates(vec[i], vec[j]);
		}
	}

	std::vector<int> indexes(size);
	for (int i = 0; i < size; i++) {
		indexes[i] = i;
	}

	int result = std::numeric_limits<int>::max();

	do {

		int total_dups = 0;

		for (i = 1; i < size; i++) {

			int s1_index = indexes[i];
			int s2_index = indexes[i - 1];

			total_dups += dups[s1_index][s2_index];
		}

		result = std::min(result, total_dups);

	} while (std::next_permutation(indexes.begin(), indexes.end()));

	std::cout << result << std::endl;

	return 0;
}
