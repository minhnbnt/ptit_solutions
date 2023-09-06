#include <stdio.h>

#define i64 long long

i64 gcd(i64 a, i64 b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		i64 m, n, a, b, i;
		scanf("%lld%lld%lld%lld", &m, &n, &a, &b);

		if (m > n) {
			i64 tmp = m;
			m = n, n = tmp;
		}

		unsigned long long result = 0;

		for (i64 i = m; i <= n; ++i)
			if (i % a == 0 || i % b == 0) {
				++result;
			}

		printf("%llu\n", result);
		fflush(stdout);
	}

	return 0;
}
