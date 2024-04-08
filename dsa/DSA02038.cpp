#include <algorithm>
#include <iostream>
#include <vector>

template <typename Iter>
void gen_subarray(Iter begin, Iter end, size_t size) {

	using T = typename std::iterator_traits<Iter>::value_type;

	static std::vector<T> sub_array;

	if (sub_array.size() == size) {

		for (T &element : sub_array) {
			std::cout << element << ' ';
		}

		std::cout.put('\n');

		return;
	}

	while (begin != end) {

		sub_array.push_back(*begin);
		begin++;

		gen_subarray(begin, end, size);

		sub_array.pop_back();
	}

	if (sub_array.empty()) {
		sub_array.shrink_to_fit();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size, sub_array_size;
		std::cin >> size >> sub_array_size;

		std::vector<int> vec(size);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::sort(vec.begin(), vec.end());

		gen_subarray(vec.begin(), vec.end(), sub_array_size);
		std::cout.flush();
	}

	return 0;
}
