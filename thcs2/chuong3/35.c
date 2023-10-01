#include <stdio.h>

int main() {
	int n, num = 1, gap = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			printf("%d ", num);
			num += gap;
			gap++;
		};
		printf("\n");
	};
	return 0;
}
