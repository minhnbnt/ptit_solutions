#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		size_t size, i, j;
		scanf("%zu", &size);

		int array[size];
		for (i = 0; i < size; i++) {
			scanf("%d", &array[i]);
		}

		int result = INT_MAX;
		for (i = 0; i < size; i++) {
			for (j = i + 1; j < size; j++) {

				const int sum = array[i] + array[j];

				if (abs(sum) < abs(result)) {
					result = sum;
				}
			}
		}

		printf("%d\n", result);
		fflush(stdout);
	}

	return 0;
}
