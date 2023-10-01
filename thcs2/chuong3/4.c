#include <stdio.h>

int main() {
	int a[4], result = 1;
	scanf("%d %d %d", &a[0], &a[1], &a[2]);
	a[3] = a[0];
	for (int i = 0; i < 3; i++) {
		if (a[i] == a[i + 1]) result++;
		if (result == 3) break;
	}
	printf("%d", result);
	return 0;
}
