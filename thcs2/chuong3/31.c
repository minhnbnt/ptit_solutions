#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) printf(" ");
		int j = 0;
		while (j <= n - i - 1) {
			j++;
			printf("%d", 2 * j);
		};
		while (j > 1) {
			j--;
			printf("%d", 2 * j);
		};
		printf("\n");
	};
	return 0;
}
