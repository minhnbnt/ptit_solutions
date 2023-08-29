#include <iostream>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, ques;
		std::cin >> ele >> ques;

		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
		}

		while (ques--) {

			unsigned i, j, k;
			std::cin >> i >> j;

			long long result = 0;
			for (k = i - 1; k < j; ++k) {
				result += vec[k];
			}

			std::cout << result << std::endl;
		}
	}

	return 0;
}
