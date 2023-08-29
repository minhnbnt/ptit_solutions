#include <iostream>
#include <list>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, pos = 0;
		std::cin >> ele;

		std::list<int> llist(ele);
		for (int &x : llist) {
			std::cin >> x;
		}
		llist.sort();

		while (!llist.empty()) {

			if (pos % 2 == 0) {
				std::cout << llist.back() << ' ';
				llist.pop_back();
			} else {
				std::cout << llist.front() << ' ';
				llist.pop_front();
			}
			++pos;
		}
		std::cout << std::endl;
	}

	return 0;
}
