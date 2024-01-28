#include <iostream>
#include <unordered_map>
#include <vector>

using i64 = long long;
using u64 = unsigned long long;

u64 count_two_sum(const std::vector<i64> &vec, i64 target) {

	u64 counter = 0;
	std::unordered_map<i64, size_t> hash_map;

	for (i64 element : vec) {
		counter += hash_map[target - element];
		++hash_map[element];
	}

	return counter;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		i64 target;
		size_t size;
		std::cin >> size >> target;

		std::vector<i64> vec(size);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		std::cout << count_two_sum(vec, target) << std::endl;
	}

	return 0;
}
