#include <cctype>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main(void) {

	std::string buf;
	std::ifstream ifs("VANBAN.in");
	std::set<std::string> words;

	while (ifs >> buf) {
		for (char &c : buf) {
			c = tolower(c);
		}
		words.insert(buf);
	}

	for (std::string word : words) {
		std::cout << word << '\n';
	}

	return 0;
}
