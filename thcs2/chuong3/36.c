#include <stdio.h>

int main() {
	int n, num = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		if (i % 2) {
			for (int j = 1; j <= i; j++) {
				num++;
				printf("%d", num);
			};
		} else {
			for (int j = i; j >= 1; j--) printf("%d", num + j);
			num += i;
		};
		printf("\n");
	};
	return 0;
}
