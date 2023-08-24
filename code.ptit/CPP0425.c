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

		int arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%d", &arr[i]);
		}

		while (1) {

			char flag = 1;

			for (i = 1; i < ele; ++i)
				if ((i % 2 == 1 && arr[i] < arr[i - 1]) ||
				    (i % 2 == 0 && arr[i] > arr[i - 1])) {
					int temp = arr[i];
					arr[i] = arr[i - 1];
					arr[i - 1] = temp;
					flag = 0;
				}

			if (flag) break;
		}

		for (i = 0; i < ele; ++i) {
			printf("%d ", arr[i]);
		}

		putchar('\n');
		fflush(stdout);
	}

	return 0;
}
