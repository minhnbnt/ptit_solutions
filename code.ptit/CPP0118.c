#include <stdio.h>

#define u64 unsigned long long

u64 gcd(u64 a, u64 b) {

	while (a > 0 && b > 0)
		if (a > b) a %= b;
		else b %= a;

	return a + b;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 a, b;

		scanf("%llu%llu", &a, &b);

		u64 g = gcd(a, b);

		printf("%llu %llu\n", a * b / g, g);
		fflush(stdout);
	}

	return 0;
}
