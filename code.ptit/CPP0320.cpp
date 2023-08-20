#include <iostream>
#include <string>
#include <unordered_set>

int is_full_number(std::string s) {

	if (s[0] == '0') return -1;
	std::unordered_set<char> set;

	for (const char &c : s) {
		if (!isdigit(c)) return -1;
		set.insert(c);
	}

	return set.size() == 10;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::cin >> std::ws >> input;

		int result = is_full_number(input);
		if (result == -1) std::cout << "INVALID";
		else std::cout << (result ? "YES" : "NO");
		std::cout << std::endl;
	}

	return 0;
}
