#include <iostream>
#include <unordered_map>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, i, target;
		std::cin >> ele >> target;

		std::unordered_map<i64, unsigned> map;
		for (i = 1; i <= ele; ++i) {

			i64 x;
			std::cin >> x;

			if (map.find(x) == map.end()) {
				map.emplace(x, i);
			}
		}

		if (map.find(target) != map.end()) {
			std::cout << map[target];
		} else std::cout << -1;
		std::cout << std::endl;
	}

	return 0;
}
