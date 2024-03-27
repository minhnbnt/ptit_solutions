#include <cmath>
#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

bool is_prime(size_t x) {

	static std::vector<bool> dp{ 0, 1 };

	if (x < dp.size()) return dp[x];

	const size_t prev_size = dp.size();
	dp.resize(x + 1, true);

	for (size_t i = 2; i <= sqrt(x); i++) {

		if (!dp[i]) continue;

		const size_t start = std::max(i, prev_size / i) * i;

		for (size_t j = start; j <= x; j += i) {
			dp[j] = false;
		}
	}

	return dp[x];
}

unsigned number_of_step(int begin, int end) {

	std::deque<int> queue{ begin };
	std::unordered_map<int, unsigned> generated{ { begin, 0 } };

	while (generated.find(end) == generated.end()) {

		const int current = queue.front();
		const unsigned number_of_step = generated[current];

		queue.pop_front();

		auto next = std::to_string(current);

		for (size_t i = 0; i < next.length(); i++) {

			const char prev_char = next[i];

			for (char digit = '0'; digit <= '9'; digit++) {

				next[i] = digit;

				const int value = std::stoi(next);

				if (generated.find(value) != generated.end()) {
					continue;
				}

				if (!is_prime(value)) {
					continue;
				}

				generated.emplace(value, number_of_step + 1);
				queue.push_back(value);
			}

			next[i] = prev_char;
		}
	}

	return generated[end];
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		int begin, end;
		std::cin >> begin >> end;

		std::cout << number_of_step(begin, end) << std::endl;
	}

	return 0;
}
