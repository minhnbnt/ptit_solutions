#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned long num;
		scanf("%lu", &num);

		while (num >= 10) {

			unsigned sum = 0;

			while (num > 0) {
				sum += num % 10;
				num /= 10;
			}

			num = sum;
		}

		printf("%lu\n", num);
		fflush(stdout);
	}

	return 0;
}
