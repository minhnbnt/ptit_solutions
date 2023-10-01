#include <cctype>
#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		std::string num;

		long long max = 0;

		for (const char &c : input) {

			if (isdigit(c)) {
				num.push_back(c);
				continue;
			}

			if (num.empty()) {
				continue;
			}

			max = std::max(std::stoll(num), max);

			num.clear();
		}

		std::cout << max << std::endl;
	}

	return 0;
}
