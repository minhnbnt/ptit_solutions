#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void merge_sort(Iter begin, Iter end) {

	using Int = typename std::iterator_traits<Iter>::value_type;

	const size_t distance = std::distance(begin, end);

	if (distance < 2) return;

	Iter middle = begin + (distance / 2);

	merge_sort(begin, middle);
	merge_sort(middle, end);

	std::vector<Int> merged(distance);
	std::merge(begin, middle, middle, end, merged.begin());

	std::copy(merged.begin(), merged.end(), begin);
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

		merge_sort(vec.begin(), vec.end());
		for (const int x : vec) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
