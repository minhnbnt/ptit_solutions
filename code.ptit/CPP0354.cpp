#include <iostream>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf;
		std::getline(std::cin >> std::ws, buf);

		const char *p = buf.c_str();
		unsigned count = 1;
		char c = *p;
		++p;
		while (true) {
			if (*p != c) {
				std::cout << c << count;

				if (*p == '\0') break;
				c = *p, count = 1,

				++p;
				continue;
			}

			++count, ++p;
		}

		std::cout << std::endl;
	}

	return 0;
}
