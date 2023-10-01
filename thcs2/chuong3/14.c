#include <stdio.h>

int main() {
	long int a;
	scanf("%ld", &a);
	int last = a % 10;
	while (a >= 10) a /= 10;
	int first = a % 10;
	printf("%d %d\n", first, last);
	return 0;
}
