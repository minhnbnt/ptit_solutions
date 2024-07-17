/*
Một bản tin M đã mã hóa bí mật thành các con số theo ánh xạ như sau:
‘A’->1, ‘B’->2, .., ‘Z’->26.

Hãy cho biết có bao nhiêu cách khác nhau để giải mã bản tin M.
Ví dụ với bản mã M=”123” nó có thể được giải mã thành
ABC (1 2 3), LC (12 3), AW(1 23).

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một xâu ký tự số M.
T, M thỏa mãn ràng buộc: 1≤T≤100;  1≤length(M)≤40.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Ví dụ:

Input:
2
123
2563

Output:
3
2
*/

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
