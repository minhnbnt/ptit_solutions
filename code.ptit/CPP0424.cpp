#include <deque>
#include <iostream>
#include <limits>

int main(void) {

	using i64 = long long;

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t ndeq, ele, i;
		std::cin >> ndeq >> ele;

		std::deque<std::deque<i64>> deqs(ndeq, std::deque<i64>(ele));
		for (std::deque<i64> &deq : deqs)
			for (i64 &x : deq) {
				std::cin >> x;
			}

		std::deque<i64> base;
		while (true) {

			size_t pos;
			i64 min = std::numeric_limits<i64>::max();

			for (i = 0; i < ndeq; ++i) {

				if (deqs[i].empty()) {
					continue;
				}

				if (deqs[i].front() < min) {
					min = deqs[i].front();
					pos = i;
				}
			}

			if (min == std::numeric_limits<i64>::max()) {
				break;
			}

			base.push_back(deqs[pos].front());
			deqs[pos].pop_front();
		}

		for (const i64 &x : base) {
			std::cout << x << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}
