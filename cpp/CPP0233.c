/*
Cho ma trận A[N][M]. Nhiệm vụ của bạn là in các phần tử của ma trận theo hình xoắn ốc ngược. Ví dụ
về in ma trận theo hình xoắn ốc ngược.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N, M là cấp
của ma trận A[][]; dòng tiếp theo đưa vào N×M số A[i][j] ; các số được viết cách nhau một vài khoảng
trống.
T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ M, N ≤100; 1≤ A[i][j] ≤105.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16
3 6
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18

Output:
10 11 7 6 5 9 13 14 15 16 12  8  4  3  2  1
11 10 9 8 7 13 14 15 16 17 18 12 6 5 4 3 2 1
*/

#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		int row, col, i, j;
		scanf("%d%d", &row, &col);

		int arr[row][col], base[row * col];
		for (i = 0; i < row; ++i) {
			for (j = 0; j < col; ++j) {
				scanf("%d", &arr[i][j]);
			}
		}

		size_t pos = 0;
		int top = 0, bottom = row - 1;
		int left = 0, right = col - 1;
		while (pos < row * col) {

			for (i = left; i <= right; ++i) {
				base[pos] = arr[top][i];
				++pos;
			}
			++top;

			for (i = top; i <= bottom; ++i) {
				base[pos] = arr[i][right];
				++pos;
			}
			--right;

			if (top <= bottom) {
				for (i = right; i >= left; --i) {
					base[pos] = arr[bottom][i];
					++pos;
				}
				--bottom;
			}

			if (left <= right) {
				for (i = bottom; i >= top; --i) {
					base[pos] = arr[i][left];
					++pos;
				}
				++left;
			}
		}
		do {
			--pos;
			printf("%d ", base[pos]);
		} while (pos > 0);
		putchar(0xa), fflush(stdout);
	}

	return 0;
}
