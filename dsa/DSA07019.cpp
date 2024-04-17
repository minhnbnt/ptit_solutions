#include <iostream>
#include <vector>

using i64 = long long;

i64 largest_rectangle_area(const std::vector<int> &vec) {

	i64 result = 0;
	size_t i, size = vec.size();

	std::vector<std::pair<int, size_t>> stack;

	for (i = 0; i < size; i++) {

		int current_index = i;

		while (!stack.empty()) {

			const auto &[height, index] = stack.back();

			if (height <= vec[i]) {
				break;
			}

			const i64 width = i - index;
			const i64 area = width * height;

			result = std::max(result, area);
			current_index = index;

			stack.pop_back();
		}

		stack.emplace_back(vec[i], current_index);
	}

	for (const auto &[height, index] : stack) {

		const i64 width = size - index;
		const i64 area = width * height;

		result = std::max(result, area);
	}

	return result;
}

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

		std::cout << largest_rectangle_area(vec) << std::endl;
	}

	return 0;
}
