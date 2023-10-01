#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int comparator(const std::string &s1, const std::string &s2) {
	return s1 + s2 > s2 + s1;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::vector<std::string> vec(ele);
		for (std::string &s : vec) {
			std::cin >> std::ws >> s;
		}

		std::sort(vec.begin(), vec.end(), comparator);

		for (const std::string &s : vec) {
			std::cout << s;
		}
		std::cout << std::endl;
	}

	return 0;
}
