#include <cstring>
#include <iostream>
#include <string>

bool beauty_of(const std::string &num) {

	for (const char &c : num)
		if (strchr("02468", c) == NULL) {
			return false;
		}

	return true;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::getline(std::cin >> std::ws, num);

		std::cout << (beauty_of(num) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
