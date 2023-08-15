#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

int main(void) {

	long long sum = 0;
	std::string buf;
	std::ifstream ifs("DATA.in");

	while (ifs >> buf) {

		int x;

		try {
			x = std::stoi(buf);
		} catch (...) {
			continue;
		}

		sum += x;
	}

	std::cout << sum << std::endl;

	return 0;
}
