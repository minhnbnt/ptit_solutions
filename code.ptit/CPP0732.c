#include <stdio.h>
#include <string.h>

typedef long long i64;

i64 gen_result(const i64 *arr, const size_t ele) {

	i64 result[ele];
	memcpy(result, arr, sizeof(i64) * ele);

	size_t i, j;
	for (i = 1; i < ele; ++i)

		for (j = 0; j < i; ++j) {

			const i64 with_i = result[j] + arr[i];

			if (arr[i] > arr[j] && result[i] < with_i) {
				result[i] = with_i;
			}
		}

	i64 max = result[0];
	for (i = 1; i < ele; ++i)
		if (max < result[i]) {
			max = result[i];
		}

	return max;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t ele, i;
		scanf("%zu", &ele);

		i64 arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%lld", arr + i);
		}

		printf("%lld\n", gen_result(arr, ele));
		fflush(stdout);
	}

	return 0;
}
