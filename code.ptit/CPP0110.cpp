#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string str;
		std::cin >> std::ws >> str;

		size_t pos = str.find("084");

		if (pos != std::string::npos) {
			str.replace(pos, 3, "");
		}

		std::cout << str << std::endl;
	}

	return 0;
}
