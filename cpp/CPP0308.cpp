#include <iostream>
#include <string>
#include <unordered_map>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		std::unordered_map<char, size_t> map;
		for (const char &c : input) {
			++map[c];
		}

		for (const char &c : input) {
			if (map[c] == 1) {
				std::cout.put(c);
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
