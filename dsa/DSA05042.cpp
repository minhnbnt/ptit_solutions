#include <iostream>
#include <unordered_set>
#include <vector>

using i64 = long long;

bool has_subarray_with_sum(const std::vector<int> &vec, i64 target_sum) {

	std::unordered_set<i64> sums{ 0 };
	i64 current_sum = 0;

	for (int element : vec) {

		current_sum += element;

		if (sums.find(current_sum - target_sum) != sums.end()) {
			return true;
		}

		sums.insert(current_sum);
	}

	return false;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t size;
		i64 target_sum;
		std::cin >> size >> target_sum;

		std::vector<int> vec(size);
		for (int &x : vec) {
			std::cin >> x;
		}

		const bool result = has_subarray_with_sum(vec, target_sum);
		std::cout << (result ? "YES" : "NO") << std::endl;
	}

	return 0;
}
