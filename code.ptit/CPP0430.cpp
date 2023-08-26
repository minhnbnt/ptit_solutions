#include <iostream>
#include <set>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::set<int> set;
		while (ele--) {
			int x;
			std::cin >> x;
			set.insert(x);
		}

		const int &L = *set.begin();
		const int &R = *set.rbegin();

		std::cout << R - L - set.size() + 1 << std::endl;
	}

	return 0;
}
