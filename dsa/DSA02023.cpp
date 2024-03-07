#include <iostream>
#include <set>
#include <string>
#include <vector>

template <typename Iter>
void print_all_name(Iter begin, Iter end, size_t size) {

	static std::vector<Iter> result;
	if (result.size() == size) {

		for (Iter it : result) {
			std::cout << *it << ' ';
		}

		std::cout.put('\n');
		return;
	}

	while (begin != end) {

		result.push_back(begin);
		begin++;

		print_all_name(begin, end, size);

		result.pop_back();
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t size, name_length, i;
	std::cin >> size >> name_length;

	std::set<std::string> names;
	for (i = 0; i < size; i++) {

		std::string name;
		std::cin >> name;

		names.insert(name);
	}

	print_all_name(names.begin(), names.end(), name_length);
	std::cout.flush();

	return 0;
}
