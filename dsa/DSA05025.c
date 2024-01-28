#include <stdio.h>
#include <stdlib.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases-- > 0) {

		size_t distance, i, j;
		scanf("%zu", &distance);

		unsigned long long dp[distance + 1];
		dp[0] = 1;

		for (i = 1; i <= distance; i++) {

			dp[i] = 0;

			for (j = 1; j <= 3; j++) {
				if (j > i) continue;
				dp[i] += dp[i - j];
			}
		}

		printf("%llu\n", dp[distance]);
	}

	return 0;
}
