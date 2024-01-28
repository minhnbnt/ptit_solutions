#include <iostream>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases-- > 0) {

		size_t size;
		unsigned target;
		std::cin >> size >> target;

		std::vector<int> vec(size);
		for (int &x : vec) {
			std::cin >> x;
		}

		std::vector<std::vector<bool>> dp(size + 1);
		dp[0].resize(target + 1, false);

		for (size_t i = 1; i <= size; i++) {

			const int current_element = vec[i - 1];

			dp[i - 1][0] = true;
			dp[i] = dp[i - 1];

			for (unsigned j = 1; j <= target; j++) {

				if (dp[i][j]) {
					continue;
				}

				if (j < current_element) {
					continue;
				}

				dp[i][j] = dp[i - 1][j - current_element];
			}

			dp[i - 1].clear();
		}

		std::cout << (dp[size][target] ? "YES" : "NO") << std::endl;
	}

	return 0;
}
