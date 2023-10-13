#include <iostream>
#include <queue>
#include <vector>

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	int rank;
	std::cin >> rank;

	std::priority_queue<int, std::vector<int>, std::greater<int>> queue;
	for (size_t i = 0; i < rank * rank; ++i) {

		int x;
		std::cin >> x;

		queue.push(x);
	}

	int i;
	std::vector<std::vector<int>> vec(rank);
	for (i = 0; i < rank; ++i) {
		vec[i].resize(rank);
	}

	int top = 0, bottom = rank - 1;
	int left = 0, right = rank - 1;
	while (top <= bottom || left <= right) {

		for (i = left; i <= right; ++i) {
			vec[top][i] = queue.top();
			queue.pop();
		}
		++top;

		for (i = top; i <= bottom; ++i) {
			vec[i][right] = queue.top();
			queue.pop();
		}
		--right;

		if (top <= bottom) {
			for (i = right; i >= left; --i) {
				vec[bottom][i] = queue.top();
				queue.pop();
			}
			--bottom;
		}

		if (left <= right) {
			for (i = bottom; i >= top; --i) {
				vec[i][left] = queue.top();
				queue.pop();
			}
			++left;
		}
	}

	for (const std::vector<int> &v : vec) {
		for (const int &x : v) {
			std::cout << x << ' ';
		}
		std::cout.put(0xa);
	}
	std::cout.flush();

	return 0;
}
