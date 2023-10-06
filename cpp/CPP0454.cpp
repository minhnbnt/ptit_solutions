#include <algorithm>
#include <iostream>
#include <vector>

using u64 = unsigned long long;

bool has_righttriangle(std::vector<u64> vec) {

	for (u64 &x : vec) x *= x;
	std::sort(vec.begin(), vec.end());

	for (int i = vec.size(); i > 0; --i) {

		u64 &hypo = vec[i - 1];
		int left = 0, right = i - 2;

		while (left != right) {
			if (vec[left] + vec[right] > hypo) --right;
			else if (vec[left] + vec[right] < hypo) ++left;
			else return true;
		}
	}

	return false;
}

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::vector<u64> vec(ele);
		for (u64 &item : vec) {
			std::cin >> item;
		}

		std::cout << (has_righttriangle(vec) ? "YES" : "NO") << std::endl;
	}

	return 0;
}
