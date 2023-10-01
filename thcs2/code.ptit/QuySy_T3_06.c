#include <stdio.h>

long UocSo;
long gcd(long a, long b) {
	if (a == 0) return b;
	return gcd(b % a, a);
};

void USCLN(long a, long b) {
	UocSo = gcd(a, b);
};

int main(void) {
	long a, b;
	scanf("%ld %ld", &a, &b);
	if (a > 0 || b > 0) {
		USCLN(a, b);
		printf("%ld\n%lld\n", //
		       UocSo, (long long)a * b / UocSo);
	}
	return 0;
}
