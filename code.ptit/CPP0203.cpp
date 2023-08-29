#include <iostream>
#include <unordered_set>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i;
		std::cin >> ele;
		std::unordered_set<i64> set(ele);

		for (i = 0; i < ele; ++i) {
			i64 x;
			std::cin >> x;
			set.insert(x);
		}

		i = 1;
		while (set.find(i) != set.end()) ++i;

		std::cout << i << std::endl;
	}

	return 0;
}
