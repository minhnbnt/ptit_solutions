#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>

unsigned get_key(const char c) {

	static const char *map[] = { "ABC", "DEF",  "GHI", "JKL",
		                         "MNO", "PQRS", "TUV", "WXYZ" };

	for (unsigned i = 2; i <= 9; ++i)
		if (strchr(map[i - 2], toupper(c)) != NULL) {
			return i;
		}

	return 0;
}

bool is_reversible(const std::vector<unsigned> &vec) {

	const size_t &size = vec.size();

	for (size_t i = 0; i < size; ++i)
		if (vec.at(i) != vec.at(size - i - 1)) {
			return false;
		}

	return true;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string input;
		std::getline(std::cin >> std::ws, input);

		std::vector<unsigned> keys;
		for (const char &c : input) {

			unsigned key_pressed = get_key(c);

			keys.push_back(key_pressed);
		}

		std::cout << (is_reversible(keys) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
