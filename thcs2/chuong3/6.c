#include <stdio.h>

int main() {
	int a[3];
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	int min = a[0];
	for (int i = 1; i < 3; i++)
		if (a[i] < min) min = a[i];
	printf("%d\n", min);
	return 0;
}
