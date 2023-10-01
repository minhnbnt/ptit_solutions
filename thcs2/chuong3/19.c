#include <math.h>
#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
		if (!(a % i)) printf("%d ", i);
	printf("\n");
	return 0;
}
