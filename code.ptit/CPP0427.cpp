#include <iostream>
#include <vector>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, i;
		std::cin >> ele;

		std::vector<i64> vec(ele);
		for (i64 &x : vec) {
			std::cin >> x;
		}

		for (i = 1; i < ele; ++i) {

			if (vec[i] == 0) {
				continue;
			}

			if (vec[i] == vec[i - 1]) {
				vec[i - 1] *= 2;
				vec[i] = 0;
			}
		}

		size_t zero_count = 0;

		for (const i64 &x : vec) {

			if (x == 0) {
				++zero_count;
				continue;
			}

			std::cout << x << ' ';
		}

		while (zero_count--) {
			std::cout << "0 ";
		}

		std::cout << std::endl;
	}

	return 0;
}
