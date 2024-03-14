#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned max(unsigned a, unsigned b, unsigned c) {

	unsigned result = a;

	if (result < b) {
		result = b;
	}

	if (result < c) {
		result = c;
	}

	return result;
}

unsigned lonest_common_subsequence(const char *s1, const char *s2,
                                   const char *s3) {

	const unsigned len1 = strlen(s1), len2 = strlen(s2), len3 = strlen(s3);

	unsigned **dp[len1 + 1], i, j, k;
	for (i = 0; i <= len1; i++) {

		dp[i] = (unsigned **)malloc(sizeof(void *) * (len2 + 1));
		for (j = 0; j <= len2; j++) {

			dp[i][j] = (unsigned *)malloc((len3 + 1) * sizeof(unsigned));
			for (k = 0; k <= len3; k++) {

				if (i == 0 || j == 0 || k == 0) {
					dp[i][j][k] = 0;
					continue;
				}

				if (s1[i - 1] == s2[j - 1] && s1[i - 1] == s3[k - 1]) {
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					continue;
				}

				dp[i][j][k] =
				    max(dp[i - 1][j][k], dp[i][j - 1][k], dp[i][j][k - 1]);
			}

			if (i == 0 || j == 0) continue;

			free(dp[i - 1][j - 1]);
		}

		if (i == 0) continue;

		free(dp[i - 1][len2]);
		free(dp[i - 1]);
	}

	const unsigned result = dp[len1][len2][len3];

	for (i = 0; i <= len2; i++) {
		free(dp[len1][i]);
	}

	free(dp[len1]);

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned len1, len2, len3;
		scanf("%u%u%u", &len1, &len2, &len3);

		char s1[101], s2[101], s3[101];
		scanf("%100s%100s%100s", s1, s2, s3);

		printf("%u\n", lonest_common_subsequence(s1, s2, s3));
		fflush(stdout);
	}

	return 0;
}
