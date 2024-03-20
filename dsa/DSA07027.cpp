#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		std::cin >> size;

		std::vector<int> vec(size);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::reverse(vec.begin(), vec.end());
		std::vector<int> stack, result;

		for (const int element : vec) {

			while (!stack.empty() && stack.back() <= element) {
				stack.pop_back();
			}

			if (stack.empty()) result.push_back(-1);
			else result.push_back(stack.back());

			stack.push_back(element);
		}

		while (!result.empty()) {
			std::cout << result.back() << ' ';
			result.pop_back();
		}

		std::cout << std::endl;
	}

	return 0;
}
