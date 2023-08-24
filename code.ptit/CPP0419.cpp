#include <iostream>
#include <set>

using i64 = long long;

void input(std::set<i64> &set) {

	size_t ele;
	std::cin >> ele;

	while (ele--) {
		i64 x;
		std::cin >> x;

		set.insert(x);
	}
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t elea, eleb;
		std::cin >> elea >> eleb;

		std::set<i64> uni, a, b;
		while (elea--) {
			i64 x;
			std::cin >> x;

			a.insert(x);
			uni.insert(x);
		}

		while (eleb--) {
			i64 x;
			std::cin >> x;

			b.insert(x);
			uni.insert(x);
		}

		for (auto &x : uni) {
			std::cout << x << ' ';
		}
		std::cout.put(0xa);
		for (auto &x : a) {
			if (b.find(x) == b.end()) {
				continue;
			}
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
