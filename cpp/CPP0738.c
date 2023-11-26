#include <stdio.h>

unsigned num_of_operators(unsigned *arr, unsigned ele) {

	unsigned increment = 0, multiple = 0;

	for (unsigned i = 0; i < ele; ++i) {

		unsigned exp = 0;
		unsigned num = arr[i];

		while (1) {

			if (num % 2 == 1) {
				++increment;
			}

			num /= 2;

			if (num == 0) break;

			++exp;
		}

		if (exp > multiple) {
			multiple = exp;
		}
	}

	return increment + multiple;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned ele, i;
		scanf("%u", &ele);

		unsigned arr[ele];
		for (i = 0; i < ele; ++i) {
			scanf("%u", arr + i);
		}

		printf("%u\n", num_of_operators(arr, ele));
		fflush(stdout);
	}

	return 0;
}
