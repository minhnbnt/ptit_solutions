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
