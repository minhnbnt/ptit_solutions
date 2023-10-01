#include <stdio.h>

int main() {
	int m, n, p;
	scanf("%d %d", &m, &n);
	int a[m], b[n];
	for (int i = 0; i < m; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) scanf("%d", &b[i]);
	scanf("%d", &p);
	for (int i = 0; i < m; i++) {
		printf("%d ", a[i]);
		if (i == p - 1)
			for (int j = 0; j < n; j++) printf("%d ", b[j]);
	};
	printf("\n");
	return 0;
}
