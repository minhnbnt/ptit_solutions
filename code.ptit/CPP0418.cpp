#include <iostream>
#include <set>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t eleA, eleB, i;
		std::cin >> eleA >> eleB;

		std::set<i64> setA, intersct;

		for (i = 0; i < eleA; ++i) {

			i64 x;
			std::cin >> x;

			setA.insert(x);
		}

		std::set<i64> uni(setA);

		for (i = 0; i < eleB; ++i) {

			i64 x;
			std::cin >> x;

			uni.insert(x);

			if (setA.find(x) != setA.end()) {
				intersct.insert(x);
			}
		}

		for (const i64 &x : uni) {
			std::cout << x << ' ';
		}
		std::cout.put(10);

		for (const i64 &x : intersct) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
