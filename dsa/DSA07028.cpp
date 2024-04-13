#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t i, size;
		std::cin >> size;

		std::vector<int> vec(size);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::vector<std::pair<int, size_t>> stack;

		for (i = 0; i < size; i++) {

			size_t current_index = i;

			while (!stack.empty()) {

				auto &[value, index] = stack.back();

				if (value > vec[i]) {
					break;
				}

				current_index = index;
				stack.pop_back();
			}

			stack.emplace_back(vec[i], current_index);

			std::cout << i - current_index + 1 << ' ';
		}

		std::cout << std::endl;
	}

	return 0;
}
