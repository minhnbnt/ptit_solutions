#include <iostream>
#include <set>
#include <string>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::set<char> se;

		while (ele--) {

			std::string s;
			std::cin >> std::ws >> s;

			for (char c : s) {
				se.insert(c);
			}
		}

		for (char c : se) {
			std::cout << c << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
