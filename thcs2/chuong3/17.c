#include <stdio.h>

int main() {
	int a, result = 1;
	scanf("%d", &a);
	while (a) {
		result *= a % 10;
		a /= 10;
	};
	printf("%d\n", result);
	return 0;
}
