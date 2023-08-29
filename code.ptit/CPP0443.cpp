#include <iostream>
#include <unordered_set>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i;
		std::cin >> ele;

		std::unordered_set<i64> set;
		for (i = 1; i < ele; ++i) {
			i64 x;
			std::cin >> x;

			set.insert(x);
		}

		i64 result = 1;
		while (set.find(result) != set.end()) {
			++result;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
