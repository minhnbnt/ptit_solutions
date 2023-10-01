#include <stdio.h>

#define i64 long long

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

		i64 max_so_far = -__INT_FAST64_MAX__, max_here = 0;
		for (i = 0; i < ele; ++i) {

			max_here += arr[i];

			if (max_here > max_so_far) {
				max_so_far = max_here;
			}

			if (max_here < 0) {
				max_here = 0;
			}
		}

		printf("%lld\n", max_so_far);
		fflush(stdout);
	}

	return 0;
}
