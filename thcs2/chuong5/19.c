#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n][n], sum1 = 0, sum2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (i < j) sum1 += arr[i][j];
			if (i > j) sum2 += arr[i][j];
		};
	printf("%d %d\n", sum1, sum2);
	return 0;
}
