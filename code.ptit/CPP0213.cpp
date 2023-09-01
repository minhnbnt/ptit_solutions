#include <algorithm>
#include <iostream>
#include <vector>

bool in_fibs(unsigned x) {

	static std::vector<unsigned> vec{ 0, 1 };

	if (x < vec.back()) {
		return std::binary_search(vec.begin(), vec.end(), x);
	}

	while (x > vec.back()) {

		const unsigned &last1 = vec.back();
		const unsigned &last2 = *std::next(vec.rbegin());

		vec.push_back(last1 + last2);

		if (x < vec.back()) {
			return false;
		}
	}

	return true;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::vector<unsigned> vec(ele);

		for (unsigned &x : vec) {
			std::cin >> x;
		}

		for (const unsigned &x : vec) {
			if (!in_fibs(x)) continue;
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
