#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t size1, size2;
		std::cin >> size1 >> size2;

		std::vector<int> vec1(size1), vec2(size2);
		for (int &x : vec1) std::cin >> x;
		for (int &x : vec2) std::cin >> x;

		std::vector<int> result;
		std::set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(),
		               std::back_inserter(result));

		for (int element : result) {
			std::cout << element << ' ';
		}
		std::cout.put('\n');

		result.clear();
		std::set_intersection(vec1.begin(), vec1.end(), vec2.begin(),
		                      vec2.end(), std::back_inserter(result));

		for (int element : result) {
			std::cout << element << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
