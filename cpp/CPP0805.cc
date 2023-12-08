#include <cctype>
#include <fstream>
#include <iostream>
#include <set>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::set<std::string> data1, data2;

	std::string word;
	std::ifstream ifs("DATA1.in");
	while (ifs >> word) {
		for (char &c : word) {
			c = tolower(c);
		}
		data1.insert(word);
	}

	ifs = std::ifstream("DATA2.in");
	while (ifs >> word) {
		for (char &c : word) {
			c = tolower(c);
		}
		data2.insert(word);
	}

	std::set<std::string> _union(data1);
	for (const std::string &s : data2) {
		_union.insert(s);
	}

	for (const std::string &s : _union) {
		std::cout << s << ' ';
	}

	std::cout.put('\n');

	for (const std::string &s : data1) {
		if (data2.find(s) == data2.end()) {
			continue;
		}
		std::cout << s << ' ';
	}

	std::cout << std::endl;

	return 0;
}
