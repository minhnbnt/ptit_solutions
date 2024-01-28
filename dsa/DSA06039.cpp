#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using i64 = long long;

std::tuple<i64, bool> duplicated_number(const std::vector<i64> &vec) {

	std::unordered_map<i64, size_t> hash_map;

	for (const i64 &x : vec) {
		hash_map[x]++;
	}

	for (const i64 &x : vec)
		if (hash_map[x] > 1) {
			return std::make_tuple(x, true);
		}

	return std::make_tuple(0, false);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t size;
		std::cin >> size;

		std::vector<i64> vec(size);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		auto [dup, has] = duplicated_number(vec);
		if (has) {
			std::cout << dup << std::endl;
		} else {
			std::cout << "NO" << std::endl;
		}
	}

	return 0;
}
