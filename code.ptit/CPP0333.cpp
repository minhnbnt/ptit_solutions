#include <iostream>
#include <sstream>
#include <string>

std::string &proper(std::string &s) {

	for (char &c : s) {
		c = tolower(c);
	}

	s[0] = toupper(s[0]);

	return s;
}

std::string &upper(std::string &s) {

	for (char &c : s) {
		c = toupper(c);
	}

	return s;
}

int main(void) {

	std::string full_name, str;
	std::getline(std::cin, full_name);
	std::istringstream iss(full_name);

	bool is_first = true;

	while (true) {

		iss >> str;

		if (iss.eof()) break;

		if (!is_first) {
			std::cout.put(' ');
		}

		is_first = false;

		std::cout << proper(str);
	}

	std::cout << ", " << upper(str) << std::endl;
}
