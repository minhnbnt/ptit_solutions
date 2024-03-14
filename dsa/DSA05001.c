#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(X, Y) X > Y ? X : Y

size_t longest_common_substr(const char *s1, const char *s2) {

	const size_t s1_len = strlen(s1), s2_len = strlen(s2);

	size_t i, j, *dp[s1_len];
	dp[0] = (size_t *)calloc(s2_len + 1, sizeof(size_t));

	for (i = 0; i < s1_len; i++) {

		dp[i + 1] = (size_t *)calloc(s2_len + 1, sizeof(size_t));

		for (j = 0; j < s2_len; j++) {

			if (s1[i] == s2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				continue;
			}

			dp[i + 1][j + 1] = MAX(dp[i + 1][j], dp[i][j + 1]);
		}

		free(dp[i]);
	}

	const size_t result = dp[s1_len][s2_len];

	free(dp[s1_len]);
	return result;
}

char *input(void) {

	char *result;
	size_t len = 0;

	getline(&result, &len, stdin);
	strtok(result, "\n");

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u%*c", &cases);

	while (cases-- > 0) {

		char *s1 = input(), *s2 = input();

		printf("%zu\n", longest_common_substr(s1, s2));
		free(s1), free(s2);
	}

	return 0;
}
