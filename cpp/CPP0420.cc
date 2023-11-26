#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele;
		i64 target;
		std::cin >> ele >> target;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		std::stable_sort(vec.begin(), vec.end(), [target](i64 a, i64 b) {
			const i64 a_gap = std::abs(a - target);
			const i64 b_gap = std::abs(b - target);

			return a_gap < b_gap;
		});

		for (const i64 x : vec) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
