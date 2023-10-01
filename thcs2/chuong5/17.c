#include <stdio.h>

int main() {
	int m, n;
	scanf("%d %d", &m, &n);
	int a[m][n], b[n][m];
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) scanf("%d", &b[i][j]);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			for (int k = 0; k < n; k++) sum += a[i][k] * b[k][j];
			printf("%d ", sum);
		};
		printf("\n");
	};
	return 0;
}
