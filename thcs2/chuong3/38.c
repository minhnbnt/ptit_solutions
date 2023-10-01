#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) printf("%c", 2 * j + 64);
		for (int j = i - 1; j > 0; j--) printf("%c", 2 * j + 62);
		printf("\n");
	};
	return 0;
}
