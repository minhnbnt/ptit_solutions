#include <cctype>
#include <iostream>
#include <string>
#include <unordered_set>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned target;
		std::string input;
		std::cin >> input >> target;

		int result = 0;

		for (size_t i = 0; i < input.length(); ++i) {

			std::unordered_set<char> char_set;

			for (size_t j = i; j < input.length(); ++j) {

				char_set.insert(tolower(input[j]));

				if (char_set.size() == target) {
					++result;
				} else if (char_set.size() > target) {
					break;
				}
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}
