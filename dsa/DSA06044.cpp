#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	size_t size;
	std::cin >> size;

	std::vector<int> vec(size);
	for (int &element : vec) {
		std::cin >> element;
	}

	std::vector<int> odd_index, even_index;
	for (size_t i = 0; i < size; i++) {

		switch (i % 2) {
		case 0:
			odd_index.push_back(vec[i]);
			break;
		case 1:
			even_index.push_back(vec[i]);
			break;
		}
	}

	std::sort(even_index.begin(), even_index.end());
	std::sort(odd_index.begin(), odd_index.end(), std::greater<int>());

	for (size_t i = 0; i < size; i++) {

		int value;

		switch (i % 2) {
		case 0:
			value = odd_index.back();
			odd_index.pop_back();
			break;
		case 1:
			value = even_index.back();
			even_index.pop_back();
			break;
		}

		std::cout << value << ' ';
	}

	std::cout << std::endl;

	return 0;
}
