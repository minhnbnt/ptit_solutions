#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
	return *(int *)a - *(int *)b;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned ele, i, j = 0;
		scanf("%u", &ele);

		int arr[ele], buf[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%d", &arr[i]);
		}
		qsort(arr, ele, sizeof(int), cmp);

		for (i = 0; i < ele; i += 2) {
			buf[i] = arr[j];
			++j;
		}
		for (i = 1; i < ele; i += 2) {
			buf[i] = arr[j];
			++j;
		}

		for (i = 0; i < ele; ++i) {
			printf("%d ", buf[i]);
		}

		putchar('\n');
		fflush(stdout);
	}

	return 0;
}
