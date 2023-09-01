#include <stdio.h>

int main(void) {

	size_t m, n, p, i, j, k;
	scanf("%lu%lu%lu", &n, &m, &p);

	int mx1[n][m], mx2[m][p];

	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) {
			scanf("%d", &mx1[i][j]);
		}
	for (i = 0; i < m; ++i)
		for (j = 0; j < p; ++j) {
			scanf("%d", &mx2[i][j]);
		}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < p; ++j) {

			int result = 0;

			for (k = 0; k < m; ++k) {
				result += mx1[i][k] * mx2[k][j];
			}

			printf("%d ", result);
		}
		putchar(0xa);
	}

	fflush(stdout);

	return 0;
}
