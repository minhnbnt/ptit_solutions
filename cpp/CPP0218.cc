#include <algorithm>
#include <iostream>
#include <unordered_set>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t ele;
		std::cin >> ele;

		std::unordered_set<i64> set;
		while (ele-- > 0) {

			i64 x;
			std::cin >> x;

			set.insert(x);
		}

		if (set.size() == 1) {
			// should be inf :0
			std::cout << 0 << std::endl;
			continue;
		}

		unsigned long long count = 0;
		const i64 max = *std::max_element(set.cbegin(), set.cend());
		for (i64 i = 1; i < max; ++i) {

			const i64 mod = max % i;

			auto it = std::find_if(set.cbegin(), set.cend(),
			                       [&mod, &i](const i64 &x) { return x % i != mod; });

			if (it == set.cend()) ++count;
		}

		std::cout << count << std::endl;
	}

	return 0;
}
