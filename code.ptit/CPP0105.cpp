#include <cstring>
#include <iostream>
#include <string>

bool all_068(std::string num) {

	const char *num_c = num.c_str();

	while (*num_c != '\0') {
		if (strchr("068", *num_c) == NULL) {
			return false;
		}
		++num_c;
	}

	return true;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string num;
		std::cin >> std::ws >> num;

		std::cout << (all_068(num) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
