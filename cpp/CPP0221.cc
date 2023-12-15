/*
Cho ma trận A[][] gồm các số nguyên dương. Nhiệm vụ của bạn là quay ma trận theo chiều kim đồng hồ.
Ví dụ về quay theo chiều kim đồng hồ ma trận A[][] dưới đây.

1   2   3           4   1   2

4   5   6           7   5   3

7   8   9           8   9   6

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào n, m tương ứng
với số hàng, số cột của ma trận A[]; dòng tiếp theo đưa vào n×m số A[i][j] ; các số được viết cách
nhau một vài khoảng trống.
T, n,m, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ n, m ≤100; 1≤ A[i][j] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
2 2
1 2 5 6
3 3
1 2 3 4 5 6 7 8 9

Output:
5 1 6 2
4 1 2 7 5 3 8 9 6
*/

#include <iostream>
#include <vector>

using i64 = long long;
using Matrix = std::vector<std::vector<i64>>;

void swap_3(i64 &prev, i64 &curr, i64 &next) {
	next = curr, curr = prev, prev = next;
}

void rotate_matrix(Matrix &vec) {

	int i, top = 0, bottom = vec.size() - 1;
	int left = 0, right = vec[0].size() - 1;

	i64 prev, next;

	while (top < bottom && left < right) {

		prev = vec[top + 1][left];

		for (i = left; i <= right; ++i) {
			swap_3(prev, vec[top][i], next);
		}
		++top;

		for (i = top; i <= bottom; ++i) {
			swap_3(prev, vec[i][right], next);
		}
		--right;

		if (top <= bottom) {
			for (i = right; i >= left; --i) {
				swap_3(prev, vec[bottom][i], next);
			}
			--bottom;
		}

		if (left <= right) {
			for (i = bottom; i >= top; --i) {
				swap_3(prev, vec[i][left], next);
			}
			++left;
		}
	}
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		unsigned row, col;
		std::cin >> row >> col;

		Matrix vec(row);
		for (std::vector<i64> &v : vec) {
			v.resize(col);
			for (i64 &x : v) {
				std::cin >> x;
			}
		}

		rotate_matrix(vec);

		for (const std::vector<i64> &v : vec) {
			for (const i64 &x : v) {
				std::cout << x << ' ';
			}
		}

		std::cout << std::endl;
	}

	return 0;
}
