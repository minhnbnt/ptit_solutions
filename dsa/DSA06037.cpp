#include <iostream>
#include <set>
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
		for (int &element : vec) {
			std::cin >> element;
		}

		std::vector<size_t> indexes;
		std::multiset<int> left, right(vec.begin(), vec.end());

		for (size_t i = 0; i < size - 1; i++) {

			left.insert(vec[i]);
			right.erase(right.find(vec[i]));

			if (*left.rbegin() <= *right.begin()) {
				indexes.push_back(i + 1);
			}
		}

		std::cout << indexes.size() << '\n';
		for (size_t index : indexes) {
			std::cout << index << ' ';
		}

		std::cout << std::endl;
	}

	return 0;
}
