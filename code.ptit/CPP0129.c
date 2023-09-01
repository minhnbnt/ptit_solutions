#include <stdio.h>

#define u64 unsigned long long

unsigned calculate(u64 N, unsigned p) {

	unsigned result = 0;

	for (u64 i = 2; i <= N; ++i) {

		u64 cloned = i;

		while (cloned % p == 0) {
			++result;
			cloned /= p;
		}
	}

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 N;
		unsigned p;
		scanf("%llu%u", &N, &p);

		printf("%u\n", calculate(N, p));
		fflush(stdout);
	}

	return 0;
}
