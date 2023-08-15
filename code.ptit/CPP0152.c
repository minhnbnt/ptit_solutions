#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned a, m;
		scanf("%u%u", &a, &m);

		unsigned result = 1;
		while (result * a % m != 1) ++result;

		printf("%u\n", result);
		fflush(stdout);
	}

	return 0;
}
