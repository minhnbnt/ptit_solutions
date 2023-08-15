#include <math.h>
#include <stdio.h>

#define u64 unsigned long long

char is_prime(u64 n) {

	for (unsigned long i = 2; i <= sqrt(n); ++i)
		if (n % i == 0) return 0;

	return n > 1;
}

int main(void) {

	u64 n;
	scanf("%llu", &n);

	puts(is_prime(n) ? "YES" : "NO");

	return 0;
}
