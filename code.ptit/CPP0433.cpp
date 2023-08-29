#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using i64 = long long;

int comparator(const std::pair<i64, size_t> &pr1,
               const std::pair<i64, size_t> &pr2) {

	if (pr1.second != pr2.second) {
		return pr1.second > pr2.second;
	}

	return pr1.first < pr2.first;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i;
		std::cin >> ele;

		std::unordered_map<i64, size_t> mp;
		for (i = 0; i < ele; ++i) {

			i64 x;
			std::cin >> x;

			++mp[x];
		}

		std::vector<std::pair<i64, size_t>> vec(mp.begin(), mp.end());
		std::sort(vec.begin(), vec.end(), comparator);

		for (const std::pair<i64, size_t> &pr : vec) {

			size_t sec = pr.second;

			while (sec--) {
				std::cout << pr.first << ' ';
			}
		}
		std::cout << std::endl;
	}

	return 0;
}
