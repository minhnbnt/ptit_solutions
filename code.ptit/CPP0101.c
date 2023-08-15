#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned long n;
		scanf("%lu", &n);

		printf("%llu\n", (unsigned long long)n * (n + 1) / 2);
	}

	return 0;
}
