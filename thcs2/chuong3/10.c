#include <stdio.h>

int main() {
	int a, i = 2;
	scanf("%d", &a);
	while (a > 1) {
		while (a % i != 0) i++;
		printf("%d", i);
		a /= i;
		if (a != 1) printf("x");
		else printf("\n");
	}
	return 0;
}
