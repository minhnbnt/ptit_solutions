#include <stdio.h>

#define i64 long long
#define max(a, b) a > b ? a : b

i64 max_noncontinuous(const i64 *arr, const size_t ele) {

	i64 has_i = arr[0], without_i = 0;

	for (size_t i = 1; i < ele; ++i) {

		const i64 result_until_i = max(has_i, without_i);

		has_i = result_until_i + arr[i];
		without_i = result_until_i;
	}

	return max(has_i, without_i);
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t ele, i;
		scanf("%lu", &ele);

		i64 arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%lld", &arr[i]);
		}

		printf("%lld\n", max_noncontinuous(arr, ele));
		fflush(stdout);
	}

	return 0;
}
