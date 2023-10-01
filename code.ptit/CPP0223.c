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
