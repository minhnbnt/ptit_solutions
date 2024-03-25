#include <iostream>
#include <vector>

class Generator {

	std::vector<int> sub_array;

public:

	template <typename Iter>
	unsigned number_of_subarray(Iter begin, Iter end, size_t size) {

		using T = typename std::iterator_traits<Iter>::value_type;

		if (sub_array.size() == size) {
			return 1;
		}

		unsigned result = 0;

		while (begin != end) {

			T current = *begin;
			begin++;

			bool can_insert = sub_array.empty() || current >= sub_array.back();

			if (!can_insert) {
				continue;
			}

			sub_array.push_back(current);

			result += number_of_subarray(begin, end, size);

			sub_array.pop_back();
		}

		return result;
	}
};

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t size, sub_array_size;
	std::cin >> size >> sub_array_size;

	std::vector<int> vec(size);
	for (int &x : vec) {
		std::cin >> x;
	}

	unsigned result =
	    Generator().number_of_subarray(vec.begin(), vec.end(), sub_array_size);

	std::cout << result << std::endl;

	return 0;
}
