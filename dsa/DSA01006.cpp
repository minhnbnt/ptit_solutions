#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		std::vector<std::string> outputs;

		unsigned size, i;
		std::cin >> size;

		std::vector<unsigned> vec(size);
		for (i = 0; i < size; i++) {
			vec[i] = i + 1;
		}

		do {

			std::ostringstream oss;

			for (auto element : vec) {
				oss << element;
			}

			outputs.push_back(oss.str());

		} while (std::next_permutation(vec.begin(), vec.end()));

		std::reverse(outputs.begin(), outputs.end());
		for (auto output : outputs) {
			std::cout << output << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
