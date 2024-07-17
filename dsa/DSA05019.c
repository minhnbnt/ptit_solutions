/*
Cho một bảng số N hàng, M cột chỉ gồm 0 và 1.
Bạn hãy tìm hình vuông có kích thước lớn nhất,
sao cho các số trong hình vuông toàn là số 1.

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 10).
Mỗi test bắt đầu bởi 2 số nguyên N, M (1 ≤ N, M ≤ 500).
N dòng tiếp theo, mỗi dòng gồm M số mô tả một hàng của bảng.

Output:
Với mỗi test, in ra đáp án là kích thước của hình vuông lớn nhất tìm được trên
một dòng.

Ví dụ:

Input:
2
6 5
0 1 1 0 1
1 1 0 1 0
0 1 1 1 0
1 1 1 1 0
1 1 1 1 1
0 0 0 0 0
2 2
0 0
0 0

Output:
3
0
*/

#include <stdio.h>
#include <stdlib.h>

int min(int a, int b, int c) {

	int result = a;

	if (b < result) {
		result = b;
	}

	if (c < result) {
		result = c;
	}

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned row, col, i, j;
		scanf("%u%u", &row, &col);

		char table[row][col];
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {

				int value;
				scanf("%d", &value);

				table[i][j] = value != 0;
			}
		}

		unsigned *dp[row + 1], result = 0;
		dp[0] = (unsigned *)calloc(col + 1, sizeof(unsigned));

		for (i = 1; i <= row; i++) {

			dp[i] = (unsigned *)malloc(sizeof(unsigned) * (col + 1));
			dp[i][0] = 0;

			for (j = 1; j <= col; j++) {

				if (!table[i - 1][j - 1]) {
					dp[i][j] = 0;
					continue;
				}

				dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
				dp[i][j] += 1;

				if (dp[i][j] > result) {
					result = dp[i][j];
				}
			}

			free(dp[i - 1]);
		}

		printf("%u\n", result);

		fflush(stdout);
		free(dp[row]);
	}

	return 0;
}
