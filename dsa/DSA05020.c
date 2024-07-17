/*
Cho bảng A[] kích thước N x M (N hàng, M cột).
Bạn được phép đi xuống dưới, đi sang phải và đi xuống ô chéo dưới.
Khi đi qua ô (i, j), điểm nhận được bằng A[i][j].

Hãy tìm đường đi từ ô (1, 1) tới ô (N, M) sao cho tổng điểm là nhỏ nhất.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 20).
Mỗi test gồm số nguyên dương N và M.
N dòng tiếp theo, mỗi dòng gồm M số nguyên A[i][j] (0 ≤ A[i] ≤ 1000).

Output:
Với mỗi test, in ra kết quả trên một dòng.

Ví dụ:

Input
1
3 3
1 2 3
4 8 2
1 5 3

Output:
8
*/

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned row, col, i, j;
		scanf("%u%u", &row, &col);

		unsigned matrix[row][col];
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				scanf("%u", &matrix[i][j]);
			}
		}

		unsigned dp[col];
		memset(dp, 0, sizeof(dp));

		for (i = 0; i < row; i++) {

			unsigned prev_dp[col];
			memcpy(prev_dp, dp, sizeof(dp));

			for (j = 0; j < col; j++) {

				if (i == 0 && j == 0) {
					dp[j] = matrix[i][j];
					continue;
				}

				unsigned result = UINT_MAX;

				if (j > 0) {
					result = fmin(result, dp[j - 1]);
				}

				if (i > 0) {
					result = fmin(result, prev_dp[j]);
				}

				if (i > 0 && j > 0) {
					result = fmin(result, prev_dp[j - 1]);
				}

				dp[j] = result + matrix[i][j];
			}
		}

		printf("%u\n", dp[col - 1]);
		fflush(stdout);
	}

	return 0;
}
