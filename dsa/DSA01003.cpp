#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t size;
		std::cin >> size;

		std::vector<unsigned> vec(size);
		for (auto &x : vec) {
			std::cin >> x;
		}

		std::next_permutation(vec.begin(), vec.end());

		for (unsigned x : vec) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
