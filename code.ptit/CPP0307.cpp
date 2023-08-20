#include <iostream>
#include <set>
#include <sstream>
#include <string>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		std::string buf1, buf2, str;
		std::getline(std::cin >> std::ws, buf1);
		std::getline(std::cin >> std::ws, buf2);
		std::istringstream iss1(buf1), iss2(buf2);

		std::set<std::string> set;
		while (iss1 >> str) set.insert(str);

		while (iss2 >> str)
			if (set.find(str) != set.end()) {
				set.erase(str);
			}

		for (const std::string &s : set) {
			std::cout << s << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
