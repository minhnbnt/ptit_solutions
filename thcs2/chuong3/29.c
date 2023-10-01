#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = n - 1; i >= 0; i--) {
		int k = 0;
		for (int j = 0; j < i; j++) printf(" ");
		while (n - i - k) {
			printf("%d", 2 * k + 1);
			k++;
		};
		while (k > 1) {
			printf("%d", 2 * k - 3);
			k--;
		};
		printf("\n");
	}
	return 0;
}
