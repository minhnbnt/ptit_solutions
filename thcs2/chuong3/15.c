#include <stdio.h>

int main() {
	int a, e = 1;
	scanf("%d", &a);
	while (a > e) e *= 10;
	e /= 10;
	int last = a / e;
	int first = a % 10;
	int mid = a - e * last - first;
	printf("%d\n", last + first * e + mid);
	return 0;
}
