#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned a, m;
		scanf("%u%u", &a, &m);

		int result = 1;
		while (result * a % m != 1) {

			++result;

			if (result > m) {
				result = -1;
				break;
			}
		}

		printf("%d\n", result);
		fflush(stdout);
	}

	return 0;
}
