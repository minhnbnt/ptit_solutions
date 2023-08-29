#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned rank, i;
		std::cin >> rank;

		std::unordered_map<i64, unsigned> map;
		for (i = 0; i < rank; ++i) {

			std::unordered_set<i64> set;
			unsigned remaining = rank;
			while (remaining--) {
				i64 input;
				std::cin >> input;
				set.insert(input);
			}

			for (const i64 &x : set) {
				++map[x];
			}
		}

		unsigned result = 0;
		for (const std::pair<i64, unsigned> &pr : map)
			if (pr.second == rank) ++result;

		std::cout << result << std::endl;
	}

	return 0;
}
