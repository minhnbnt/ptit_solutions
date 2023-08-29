#include <iostream>
#include <set>

int main(void) {

	std::set<int> set;

	unsigned ele;
	std::cin >> ele;

	while (ele--) {
		int x;
		std::cin >> x;
		set.insert(x);
	}

	for (const int &x : set) {
		std::cout << x << ' ';
	}
	std::cout << std::endl;

	return 0;
}
