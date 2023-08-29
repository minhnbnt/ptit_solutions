#include <iostream>
#include <string>
#include <unordered_set>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);

		unsigned k;
		std::cin >> k;

		if (buf.length() < 26) {
			std::cout << 0 << std::endl;
			continue;
		}

		std::unordered_set<char> char_set;
		for (const char &c : buf) {
			char_set.insert(c);
		}

		if (26 - char_set.size() > k) {
			std::cout << 0 << std::endl;
		} else std::cout << 1 << std::endl;
	}

	return 0;
}
