#include <iostream>
#include <unordered_map>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		std::cin >> ele;

		std::unordered_map<i64, size_t> map;
		while (ele--) {

			i64 input;
			std::cin >> input;

			if (map.find(input) != map.end()) {
				++map[input];
			} else map.emplace(input, 1);
		}

		size_t result = 0;
		for (auto &pair : map) {
			size_t &count = pair.second;
			if (count > 1) {
				result += count;
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}
