#include <stdio.h>

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a % b || a % c) printf("0\n");
	else printf("1\n");
	return 0;
}
