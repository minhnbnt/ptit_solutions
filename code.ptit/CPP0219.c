#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned row, col, i, j, k;
		scanf("%u%u", &row, &col);

		int arr[row][col], fill[row][col];
		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j) {
				scanf("%d", &arr[i][j]);
				fill[i][j] = 0;
			}

		for (i = 0; i < row; ++i)
			for (j = 0; j < col; ++j) {
				if (arr[i][j] == 0) continue;

				for (k = 0; k < row; ++k) {
					fill[k][j] = 1;
				}
				for (k = 0; k < col; ++k) {
					fill[i][k] = 1;
				}
			}

		for (i = 0; i < row; ++i) {
			for (j = 0; j < col; ++j) {
				printf("%d ", fill[i][j]);
			}
			putchar(0xa);
		}
	}

	return 0;
}
