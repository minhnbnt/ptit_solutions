/*
Cho ma trận A[N][M]. Nhiệm vụ của bạn là in các phần tử của ma trận theo hình xoắn ốc.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test gồm hai dòng: dòng đầu tiên đưa vào N, M là cấp
của ma trận A[][]; dòng tiếp theo đưa vào N×M số A[i][j] ; các số được viết cách nhau một vài khoảng
trống.
T, M, N, A[i][j] thỏa mãn ràng buộc: 1≤ T ≤100; 1≤ M, N ≤100; 1≤ A[i][j] ≤10^5.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

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

#define i64 long long

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		int row, col;
		scanf("%d%d", &row, &col);

		long long arr[row][col];
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j) {
				scanf("%lld", &arr[i][j]);
			}

		int top = 0, bottom = row - 1;
		int left = 0, right = col - 1;
		while (top <= bottom && left <= right) {

			for (int i = left; i <= right; ++i) {
				printf("%lld ", arr[top][i]);
			}
			++top;

			for (int i = top; i <= bottom; ++i) {
				printf("%lld ", arr[i][right]);
			}
			--right;

			if (top <= bottom) {
				for (int i = right; i >= left; --i) {
					printf("%lld ", arr[bottom][i]);
				}
				--bottom;
			}

			if (!(left <= right)) continue;

			for (int i = bottom; i >= top; --i) {
				printf("%lld ", arr[i][left]);
			}
			++left;
		}

		putchar(0xa), fflush(stdout);
	}

	return 0;
}
