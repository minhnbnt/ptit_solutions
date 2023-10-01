#include <deque>
#include <iostream>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned row, col, i, j;
		std::cin >> row >> col;

		std::deque<std::deque<i64>> deq(row + col - 1);
		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j) {

				i64 x;
				std::cin >> x;

				const unsigned pos = i + j;

				if (pos % 2 == 0) {
					deq[pos].push_front(x);
				} else {
					deq[pos].push_back(x);
				}
			}

		for (const std::deque<i64> &d : deq)
			for (const i64 &x : d) {
				std::cout << x << ' ';
			}
		std::cout << std::endl;
	}

	return 0;
}
