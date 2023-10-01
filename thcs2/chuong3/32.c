#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int num = 1;
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= j; i++) {
			printf("%d", num);
			num++;
		};
		printf("\n");
	};
	return 0;
}
