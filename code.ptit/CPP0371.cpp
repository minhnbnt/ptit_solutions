#include <cctype>
#include <iostream>
#include <unordered_set>

int main(void) {

	const std::unordered_set<char> aeiou = { 'a', 'e', 'i', 'o', 'u', 'y' };

	std::string buf;
	std::getline(std::cin, buf);

	for (const char &c : buf) {

		const char x = tolower(c);

		if (aeiou.find(x) != aeiou.end()) {
			continue;
		}

		std::cout << '.' << x;
	}
	std::cout << std::endl;

	return 0;
}
