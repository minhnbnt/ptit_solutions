/*
Cho ma trận vuông A[N][N]. Tìm số phép biến đổi ít nhất để tổng theo các hàng, các cột của ma trận
đều bằng nhau. Biết mỗi phép biến đổi bạn chỉ được phép tăng một phần tử bất kỳ của ma trận lên 1
đơn vị.

1   2         4   3
        -->
3   4         3   4

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N là cấp của
ma trận A[N][N]; dòng tiếp theo đưa vào N×N số A[i][j] ; các số được viết cách nhau một vài khoảng
trống.
T, N, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ N ≤100; 1≤ A[i][j] ≤150.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
2
1 2 3 4
3
1 2 3 4 2 3 3 2 1

Output:
4
6
*/

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

	unsigned cases;
	std::cin >> cases;

	while (cases--) {

		size_t rank, i, j;
		std::cin >> rank;

		int sum = 0;
		std::vector<int> row(rank, 0), col(rank, 0);
		for (i = 0; i < rank; ++i)
			for (j = 0; j < rank; ++j) {

				int x;
				std::cin >> x;

				sum += x;
				row[i] += x;
				col[j] += x;
			}

		const int max_row = *std::max_element(row.cbegin(), row.cend());
		const int max_col = *std::max_element(col.cbegin(), col.cend());

		std::cout << std::max(max_row, max_col) * rank - sum << std::endl;
	}

	return 0;
}
