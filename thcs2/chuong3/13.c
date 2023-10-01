#include <stdio.h>

int main() {
	int a, i = 0;
	scanf("%d", &a);
	while (a > 0) {
		a /= 10;
		i++;
	};
	printf("%d\n", i);
	return 0;
}
