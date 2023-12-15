/*
Cho ma trận vuông A cỡ N*N chỉ bao gồm các số nguyên dương không quá 1000. Hãy sắp đặt các giá trị
trong ma trận A sao cho các số được điền lần lượt theo kiểu xoắn ốc tăng dần, theo chiều kim đồng
hồ.

Input
Dòng đầu ghi số N (2 < N < 20).
N dòng tiếp theo ghi ma trận A, các giá trị nguyên dương và không quá 1000.

Output
Ghi ra ma trận kết quả

Ví dụ:
Input:
3
3 6 1
8 7 9
4 12 5

Output:
1 3 4
9 12 5
8 7 6
*/

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
