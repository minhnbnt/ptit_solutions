#include <iostream>
#include <set>
#include <vector>

template <typename Iter>
void all_names(Iter begin, Iter end, size_t size) {

	static std::vector<Iter> vec;
	if (vec.size() == size) {

		for (Iter &it : vec) {
			std::cout << *it << ' ';
		}

		std::cout.put('\n');
		return;
	}

	while (begin != end) {

		vec.push_back(begin);

		all_names(++begin, end, size);

		vec.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t size, length_of_name;
	std::cin >> size >> length_of_name;

	std::set<std::string> set;
	for (size_t i = 0; i < size; ++i) {

		std::string token;
		std::cin >> token;

		set.insert(token);
	}

	all_names(set.begin(), set.end(), length_of_name);

	return 0;
}
