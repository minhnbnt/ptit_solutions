#include <iostream>
#include <vector>

template <typename Iter>
unsigned generate_and_count(Iter begin, Iter end, size_t size, int target_sum) {

	if (size == 0) {
		return target_sum == 0 ? 1 : 0;
	}

	unsigned result = 0;
	for (Iter it = begin; it != end; it++) {
		result += generate_and_count(it + 1, end, size - 1, target_sum - *it);
	}

	return result;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::vector<unsigned> numbers;

	while (true) {

		unsigned vec_size, result_size, target_sum;
		std::cin >> vec_size >> result_size >> target_sum;

		numbers.resize(vec_size);

		if (numbers.empty()) {
			break;
		}

		for (unsigned i = 0; i < vec_size; i++) {
			numbers[i] = i + 1;
		}

		unsigned result = generate_and_count(numbers.begin(), numbers.end(),
		                                     result_size, target_sum);

		std::cout << result << std::endl;
	}

	return 0;
}
