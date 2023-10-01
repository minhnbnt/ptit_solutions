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

		for (i = 0; i < ele; ++i) {

			if (i == 0) {
				printf("%lld ", arr[i] * arr[i + 1]);
				continue;
			}
			if (i == ele - 1) {
				printf("%lld\n", arr[i] * arr[i - 1]);
				continue;
			}

			printf("%lld ", arr[i - 1] * arr[i + 1]);
		}
		fflush(stdout);
	}

	return 0;
}
