/*
Cho ma trận A[N][M]. Hãy tìm hạng của ma trận A[N][M]. Hạng của ma trận (Rank Matrix) là số các cột
hoặc các hàng độc lập tuyến tính. . Ví dụ hạng của ma trận dưới đây là 2 vì có hàng 1 và hàng 2 là
phụ thuộc tuyến tính.

10   20   10
20   40   20
30   50   0

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: Dòng đầu tiên đưa vào hai số N, M ;
dòng tiếp là N×M các phần tử của ma trận A[][]; các phần tử được viết cách nhau một vài khoảng
trống.
T, N, M, A[i][j] thỏa mãn ràng buộc: 1≤T≤100; 1≤ N, M ≤15; -10^2≤ A[i][j] ≤10^2.
Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
3 3
10 20 10 20 40 20 30 50 0
3 3
10 20 10 -20 -30 10 30 50 0

Output:
2
2
*/

#include <iostream>
#include <vector>

using Matrix = std::vector<std::vector<int>>;

size_t rank_of_matrix(Matrix &mx) {

	size_t rank = mx.size();

	for (size_t row = 0; row < rank; ++row) {

		if (mx[row][row] != 0) {

			for (size_t col = 0; col < mx.size(); ++col) {

				if (row == col) {
					continue;
				}

				const double ratio = double(mx[col][row]) / mx[row][row];
				for (size_t i = 0; i < rank; ++i) {
					mx[col][i] -= ratio * mx[row][i];
				}
			}

			continue;
		}

		bool is_reduce = true;
		for (size_t i = row + 1; i < mx.size(); ++i)
			if (mx[i][row] != 0) {

				std::swap(mx[row], mx[i]);

				is_reduce = false;
				break;
			}

		if (is_reduce) {

			--rank;

			for (size_t i = 0; i < mx.size(); ++i) {
				mx[i][row] = mx[i][rank];
			}
		}

		--row;
	}

	return rank;
}

int main(void) {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr), std::cout.tie(nullptr);

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t row, col;
		std::cin >> row >> col;

		Matrix mx(row, std::vector<int>(col));
		for (std::vector<int> &vec : mx) {
			for (int &x : vec) {
				std::cin >> x;
			}
		}

		std::cout << rank_of_matrix(mx) << std::endl;
	}

	return 0;
}
