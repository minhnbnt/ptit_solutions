#include <algorithm>
#include <iostream>
#include <string>

int mod_11(std::string s) {

	std::reverse(s.begin(), s.end());

	int result = 0, base = 1;
	for (const char &c : s) {

		int x = (c - '0') * base;

		result = (result + x) % 11;

		base = (base * 10) % 11;
	}

	return result;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::cin >> std::ws >> num;

		std::cout << (mod_11(num) == 0) << std::endl;
	}

	return 0;
}
