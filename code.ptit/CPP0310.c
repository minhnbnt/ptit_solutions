#include <stdio.h>

#define i64 long long
#define u64 unsigned long long

void gen_diff(u64 *min, u64 *max, u64 x) {

	u64 base = 1;

	while (x > 0) {

		switch (x % 10) {

		case 5:
			*max += base;
			break;

		case 6:
			*min -= base;
			break;
		}

		base *= 10;
		x /= 10;
	}
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 x1, x2;
		scanf("%llu%llu", &x1, &x2);

		u64 min, max;
		min = max = x1 + x2;

		gen_diff(&min, &max, x1);
		gen_diff(&min, &max, x2);

		printf("%llu %llu\n", min, max);
		fflush(stdout);
	}

	return 0;
}
