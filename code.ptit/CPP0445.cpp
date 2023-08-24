#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		i64 first = std::numeric_limits<i64>::max(), second;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
			if (x < first) {
				second = first;
				first = x;
			} else if (x != first && x < second) {
				second = x;
			}
		}

		if (second == std::numeric_limits<i64>::max()) {
			std::cout << -1 << std::endl;
			continue;
		}

		std::cout << first << ' ' << second << std::endl;
	}

	return 0;
}
