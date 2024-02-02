#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		int target_index;
		size_t size1, size2;
		std::cin >> size1 >> size2 >> target_index;

		std::vector<int> vec1(size1), vec2(size2);
		for (int &x : vec1) std::cin >> x;
		for (int &x : vec2) std::cin >> x;

		std::vector<int> merged;
		std::merge(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),
		           std::back_inserter(merged));

		std::cout << merged.at(target_index - 1) << std::endl;
	}

	return 0;
}
