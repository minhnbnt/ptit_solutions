#include <stdio.h>
#include <stdlib.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		typedef unsigned long long u64;

		unsigned n, k;
		scanf("%u%u", &n, &k);

		u64 **dp = (u64 **)malloc(sizeof(u64 *) * (n + 1));
		for (unsigned i = 0; i <= n; i++) {

			unsigned dpISize = i < k ? i : k;
			dp[i] = (u64 *)malloc(sizeof(u64) * (dpISize + 1));

			for (unsigned j = 0; j <= dpISize; j++) {

				if (j == 0 || i == j) {
					dp[i][j] = 1;
					continue;
				}

				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				dp[i][j] %= (u64)1e9 + 7;
			}

			if (i > 0) free(dp[i - 1]);
		}

		printf("%llu\n", dp[n][k]);
		fflush(stdout);

		free(dp[n]), free(dp);
	}

	return 0;
}
