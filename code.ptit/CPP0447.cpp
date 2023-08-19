#include <iostream>
#include <queue>

int main(void) {

	using i64 = long long;

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned ele, n;
		std::cin >> ele >> n;

		std::priority_queue<i64> pq;
		while (ele--) {

			i64 x;
			std::cin >> x;

			pq.push(x);
		}

		while (n--) {
			std::cout << pq.top() << ' ';
			pq.pop();
		}
		std::cout << std::endl;
	}

	return 0;
}
