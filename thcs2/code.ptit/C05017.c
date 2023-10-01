/*
Cho ma trận A[N][M]. Nhiệm vụ của bạn là in các phần tử của ma trận theo hình
xoắn ốc. Ví dụ về in ma trận theo hình xoắn ốc như dưới đây:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10.

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

Input:

Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên
đưa vào N, M là cấp của ma trận A[][]; dòng tiếp theo đưa vào N×M số A[i][j]. T,
M, N, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ M, N ≤100; 1≤ A[i][j] ≤10^5.
Output: Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:
Input:
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

Output:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
1 2 3 4 8 12 11 10 9 5 6 7
*/

#include <stdio.h>
#include <stdlib.h>

const char x[] = { 1, 0, -1, 0 };
const char y[] = { 0, 1, 0, -1 };

int main(void) {
	unsigned testcases;
	scanf("%u", &testcases);
	while (testcases--) {
		unsigned rows, cols, i, j;
		scanf("%u%u", &rows, &cols);
		unsigned arr[rows + 1][cols + 2];
		unsigned long size = rows * cols;
		for (i = 0; i < rows; ++i) {
			for (j = 1; j <= cols; ++j) //
				scanf("%u", &arr[i][j]);
			arr[i][0] = arr[i][cols + 1] = __UINT32_MAX__;
		}
		for (j = 0; j <= cols + 1; ++j) //
			arr[rows][j] = __UINT32_MAX__;
		i = j = 0;
		char flag = 0;
		while (size > 0) {
			while (arr[i + y[flag]][j + x[flag]] != __UINT32_MAX__) {
				i += y[flag], j += x[flag];
				printf("%u ", arr[i][j]);
				--size, arr[i][j] = __UINT32_MAX__;
			}
			if (++flag > 3) flag = 0;
		}
		putchar('\n');
	}
	return 0;
}
