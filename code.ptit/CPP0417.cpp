#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		std::vector<i64> cloned(vec);
		std::sort(cloned.begin(), cloned.end());

		size_t begin = 0, end = vec.size() - 1;
		while (vec[end] == cloned[end]) --end;
		while (vec[begin] == cloned[begin]) ++begin;

		std::cout << begin + 1 << ' ' << end + 1 << std::endl;
	}

	return 0;
}
