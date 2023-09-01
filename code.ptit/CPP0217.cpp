#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned rank, target;
		std::cin >> rank >> target;

		std::vector<int> vec(rank * rank);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::sort(vec.begin(), vec.end());

		std::cout << vec.at(target - 1) << std::endl;
	}

	return 0;
}
