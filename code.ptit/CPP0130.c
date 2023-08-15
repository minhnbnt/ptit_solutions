#include <math.h>
#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned long long n;
		scanf("%llu", &n);

		for (unsigned long i = 2; i <= sqrt(n); ++i)
			while (n % i == 0) {
				n /= i;
				printf("%lu ", i);
			}
		if (n > 1) printf("%llu ", n);
		putchar('\n'), fflush(stdout);
	}

	return 0;
}
