#include <stdio.h>
#include <stdlib.h>

typedef long long i64;

i64 ll_abs(i64 x) {
	if (x < 0) x = -x;
	return x;
}

i64 target;
int cmp(const void *a, const void *b) {
	i64 x = ll_abs(*(i64 *)a - target);
	i64 y = ll_abs(*(i64 *)b - target);

	return x - y;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		i64 ele, i;
		scanf("%lld%lld", &ele, &target);

		i64 arr[ele];
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
