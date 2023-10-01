#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int temp = 2 * i;
		for (int j = n - i; j > 0; j--) {
			printf("%c", temp + 63);
			temp += 2;
		};
		printf("\n");
	};
	return 0;
}
