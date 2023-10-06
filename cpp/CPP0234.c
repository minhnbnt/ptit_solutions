#include <stdio.h>

int main(void) {

	typedef long long i64;

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t target;
		int row, col, i, j;
		scanf("%d%d%zu", &row, &col, &target);

		i64 arr[row][col], base[row * col];
		for (i = 0; i < row; ++i) {
			for (j = 0; j < col; ++j) {
				scanf("%lld", arr[i] + j);
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

			for (j = top; j <= bottom; ++j) {
				base[pos] = arr[j][right];
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
				for (j = bottom; j >= top; --j) {
					base[pos] = arr[j][left];
					++pos;
				}
				++left;
			}
		}

		printf("%lld\n", base[target - 1]);
		fflush(stdout);
	}

	return 0;
}
