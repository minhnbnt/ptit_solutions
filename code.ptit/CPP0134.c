#include <math.h>
#include <stdio.h>

int calculate(unsigned N, unsigned k) {

	for (unsigned i = 2; i <= sqrt(N); i++)
		while (N % i == 0) {

			N /= i, --k;

			if (k == 0) return i;
		}

	if (N > 1 && k == 1) return N;
	return -1;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned N, k;
		scanf("%u%u", &N, &k);

		int result = calculate(N, k);

		printf("%d\n", result);
		fflush(stdout);
	}

	return 0;
}
