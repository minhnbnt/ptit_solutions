#include <stdio.h>

int main(void) {

	unsigned n, i;
	scanf("%u", &n);

	unsigned long long sum = 0, prev = 1;

	for (i = 1; i <= n; i++) {
		prev *= i;
		sum += prev;
	}

	printf("%llu\n", sum);

	return 0;
}
