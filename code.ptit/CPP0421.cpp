#include <iostream>
#include <unordered_set>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		using i64 = long long;

		size_t ele, i;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		std::unordered_set<i64> set;
		for (i64 &x : vec) {

			std::cin >> x;

			if (x >= 0) {
				set.insert(x);
			}
		}

		for (i = 0; i < ele; ++i) {

			if (set.find(i) != set.end()) {
				std::cout << i << ' ';
				continue;
			}

			std::cout << "-1 ";
		}

		std::cout << std::endl;
	}

	return 0;
}
