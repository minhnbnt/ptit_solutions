#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int j = 0;
		while (i - j) {
			j++;
			printf("%d", 2 * j);
		};
		while (j > 1) {
			j--;
			printf("%d", 2 * j);
		};
		printf("\n");
	}
	return 0;
}
