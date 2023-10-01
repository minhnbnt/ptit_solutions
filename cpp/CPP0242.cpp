#include <iostream>
#include <limits>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ele, i, j;
		std::cin >> ele;

		std::vector<int> vec1(ele), vec2(ele);
		for (int &x : vec1) std::cin >> x;
		for (int &x : vec2) std::cin >> x;

		size_t result = 0;
		for (size_t i = 0; i < ele; ++i) {

			size_t length = 0;
			long long sum1 = 0, sum2 = 0;

			for (size_t j = i; j < ele; ++j) {

				sum1 += vec1[j], sum2 += vec2[j];

				++length;

				if (sum1 == sum2 && result < length) {
					result = length;
				}
			}
		}

		std::cout << result << std::endl;
	}

	return 0;
}
