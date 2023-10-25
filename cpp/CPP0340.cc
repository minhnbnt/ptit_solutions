#include <iostream>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;

u64 gen_result(const std::vector<short> &vec, unsigned mod) {

	std::unordered_map<unsigned, u64> map;

	for (const short &num : vec) {

		const std::unordered_map<unsigned, u64> prev_map(map);

		for (const auto &[x, count] : prev_map) {
			unsigned target = x * 10 + num;
			map[target % mod] += count;
		}

		++map[num % mod];
	}

	return map.at(0);
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t len;
		unsigned mod;
		std::cin >> len >> mod >> std::ws;

		std::vector<short> vec(len);
		for (short &x : vec) {
			x = std::cin.get() - '0';
		}

		std::cout << gen_result(vec, mod) << std::endl;
	}

	return 0;
}
