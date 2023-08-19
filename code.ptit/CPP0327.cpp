#include <iostream>
#include <string>

int mod_5(std::string s) {

	size_t pos = s.length();
	int base = 1, result = 0;

	do {
		--pos;
		if (s[pos] == '1') {
			result = (result + base) % 5;
		}
		base = (base * 2) % 5;
	} while (pos != 0);

	return result;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::cin >> std::ws >> input;

		std::cout << (mod_5(input) == 0 ? "Yes" : "No") << std::endl;
	}

	return 0;
}
