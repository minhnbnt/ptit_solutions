#include <cctype>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		char c;
		std::cin >> std::ws >> c;

		if (isupper(c)) std::cout << (char)tolower(c) << std::endl;
		else std::cout << (char)toupper(c) << std::endl;
	}

	return 0;
}
