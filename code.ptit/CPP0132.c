#include <math.h>
#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned long long n;
		scanf("%llu", &n);
		unsigned long result, i;

		for (i = 2; i <= sqrt(n); ++i)
			while (n % i == 0) {
				result = i;
				n /= i;
			}
		if (n > 1) result = n;

		printf("%lu\n", result);
		fflush(stdout);
	}

	return 0;
}
