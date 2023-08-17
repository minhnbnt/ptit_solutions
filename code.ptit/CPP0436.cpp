#include <iostream>
#include <set>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::set<int> set;
		std::vector<int> vec(ele);
		for (int &x : vec) {
			std::cin >> x;
			set.insert(x);
		}

		for (int x : vec) {

			std::set<int>::iterator it = std::next(set.find(x));

			if (it != set.end()) {
				std::cout << *it << ' ';
			} else std::cout << "_ ";
		}
		std::cout << std::endl;
	}

	return 0;
}
