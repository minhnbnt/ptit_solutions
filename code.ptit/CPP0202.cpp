#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, i;
		std::cin >> ele;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::sort(vec.begin(), vec.end());

		unsigned result = std::numeric_limits<unsigned>::max();
		for (i = 1; i < ele; ++i) {
			unsigned gap = vec[i] - vec[i - 1];
			if (gap < result) {
				result = gap;
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}
