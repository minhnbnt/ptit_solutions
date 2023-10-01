#include <stdio.h>

int main() {
	int a, result = 1;
	long int b;
	scanf("%d", &a);
	for (int i = 2; i <= a; i++) result *= i;
	printf("%d\n", result);
	return 0;
}
