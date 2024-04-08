#include <iostream>
#include <queue>
#include <vector>

using u64 = unsigned long long;

const u64 MOD = 1e9 + 7;

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t size;
		std::cin >> size;

		std::priority_queue<u64, std::vector<u64>, std::greater<u64>> queue;

		while (queue.size() < size) {

			u64 length;
			std::cin >> length;

			queue.push(length % MOD);
		}

		u64 result = 0;

		while (queue.size() > 1) {

			const u64 first = queue.top();
			queue.pop();

			const u64 second = queue.top();
			queue.pop();

			const u64 new_rope = (first + second) % MOD;
			queue.push(new_rope);

			result = (result + new_rope) % MOD;
		}

		std::cout << result << std::endl;
	}

	return 0;
}
