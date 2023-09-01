#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::vector<unsigned> vec(ele);
		for (unsigned &x : vec) {
			std::cin >> x;
		}

		std::prev_permutation(vec.begin(), vec.end());

		for (const unsigned &x : vec) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
