#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned long long u64;

u64 number_of_decoded(const char *nums) {

	if (nums[0] == '0') {
		return 0;
	}

	const size_t length = strlen(nums);

	u64 dp[length + 1];
	dp[0] = 1;

	for (size_t i = 0; i < length; i++) {

		char str[] = { nums[i - 1], nums[i], '\0' };
		const int char_id = atoi(str);

		dp[i + 1] = 0;

		if (char_id <= 26 && char_id >= 10) {
			dp[i + 1] += dp[i - 1];
		}

		if (nums[i] != '0') {
			dp[i + 1] += dp[i];
			continue;
		}

		if (nums[i] > '2') {
			return 0;
		}
	}

	return dp[length];
}

int main(void) {

	unsigned cases;
	scanf("%u%*c", &cases);

	while (cases-- > 0) {

		size_t capacity;
		char *nums = NULL;
		getline(&nums, &capacity, stdin);

		printf("%llu\n", number_of_decoded(nums));
		fflush(stdout);
		free(nums);
	}

	return 0;
}
