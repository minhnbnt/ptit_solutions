#include <iostream>
#include <regex>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		static const std::regex reg(".*86$");

		std::string str;
		std::cin >> std::ws >> str;

		std::cout << std::regex_match(str, reg) << std::endl;
	}

	return 0;
}
