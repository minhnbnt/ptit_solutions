#include <stdio.h>
#include <stdlib.h>

typedef long long i64;

int cmp(const void *a, const void *b) {
	return *(i64 *)a > *(i64 *)b;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t eleA, eleB, i;
		scanf("%lu%lu", &eleA, &eleB);
		const size_t ele = eleA + eleB;

		i64 arr[eleA + eleB];
		for (i = 0; i < ele; ++i) {
			scanf("%lld", &arr[i]);
		}

		qsort(arr, ele, sizeof(i64), cmp);

		for (i = 0; i < ele; ++i) {
			printf("%lld ", arr[i]);
		}
		putchar(0xa), fflush(stdout);
	}

	return 0;
}
