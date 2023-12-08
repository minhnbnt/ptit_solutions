#include <algorithm>
#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::cin >> std::ws >> input;

		std::string::reverse_iterator it1 =
			std::is_sorted_until(input.rbegin(), input.rend(), std::greater<char>());

		if (it1 == input.rend()) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::string::reverse_iterator it2 = input.rbegin();

		while (*it2 >= *it1 || *it2 == *std::next(it2)) {
			++it2;
		}

		std::swap(*it1, *it2);

		std::cout << input << std::endl;
	}

	return 0;
}
