#include <stdio.h>

#define u64 unsigned long long

u64 bin_pow(u64 x, u64 y, const u64 p) {

	u64 result = 1;

	while (y > 0) {

		if (y & 1) result = (result * x) % p;

		x = (x * x) % p, y /= 2;
	}

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 x, y, p;
		scanf("%llu%llu%llu", &x, &y, &p);

		printf("%llu\n", bin_pow(x, y, p));
		fflush(stdout);
	}

	return 0;
}
