#include <stdio.h>
#include <string.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned n, i, j;
		scanf("%u", &n);

		int arr[n];
		unsigned tmp[n], result = 0;
		for (i = 0; i < n; ++i) {
			tmp[i] = 0;
			scanf("%d", &arr[i]);

			unsigned max = 0;

			for (j = 0; j < i; ++j)
				if (max < tmp[j] && arr[j] < arr[i]) {
					max = tmp[j];
				}

			tmp[i] = max + 1;
			if (tmp[i] > result) {
				result = tmp[i];
			}
		}

		printf("%u\n", result);
		fflush(stdout);
	}

	return 0;
}
