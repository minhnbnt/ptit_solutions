#include <algorithm>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int id;
		std::cin >> id;
		std::cout << id << ' ';

		std::string digits;
		std::cin >> std::ws >> digits;

		bool is_biggest = !std::next_permutation(digits.begin(), digits.end());
		std::cout << (is_biggest ? "BIGGEST" : digits) << std::endl;
	}

	return 0;
}
