#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n][n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++) {
		int result = 0;
		for (int j = 0; j < n; j++) result += a[i][j];
		printf("%d ", result);
	};
	printf("\n");
	for (int i = 0; i < n; i++) {
		int result = 0;
		for (int j = 0; j < n; j++) result += a[j][i];
		printf("%d ", result);
	};
	printf("\n");
	return 0;
}
