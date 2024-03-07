#include <deque>
#include <iostream>

using u64 = unsigned long long;

unsigned number_of_bdn(u64 n) {

	if (n < 2) return n;

	std::deque<u64> queue{ 1 };
	unsigned result = 1;

	while (true) {

		u64 current = queue.front();
		queue.pop_front();

		for (u64 num : { current * 10, current * 10 + 1 }) {

			if (num > n) {
				return result;
			}

			queue.push_back(num);
			result++;
		}
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		u64 target_num;
		std::cin >> target_num;

		std::cout << number_of_bdn(target_num) << std::endl;
	}

	return 0;
}
