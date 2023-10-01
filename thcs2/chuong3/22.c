#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d", &a, &b);
	c = a * b;
	while (a != b)
		if (a > b) a -= b;
		else b -= a;
	printf("%d\n", c / a);
	return 0;
}
