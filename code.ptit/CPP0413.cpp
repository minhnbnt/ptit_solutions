#include <algorithm>
#include <deque>
#include <iostream>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL), std::cout.tie(NULL);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele;
		std::cin >> ele;

		std::deque<int> deq(ele);
		for (int &x : deq) {
			std::cin >> x;
		}

		std::sort(deq.begin(), deq.end());

		unsigned i = 0;
		while (!deq.empty()) {
			if (i % 2 == 0) {
				std::cout << deq.back() << ' ';
				deq.pop_back();
			} else {
				std::cout << deq.front() << ' ';
				deq.pop_front();
			}
			++i;
		}
		std::cout << std::endl;
	}

	return 0;
}
