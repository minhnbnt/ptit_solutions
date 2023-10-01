#include <math.h>
#include <stdio.h>

int prime(int n) {
	if (n == 1) return 0;
	else if (n == 2) return 1;
	for (int i = 2; i <= sqrt(n); i++)
		if (!(n % i)) return 0;
	return 1;
}

int main() {
	int n;
	scanf("%d", &n);
	int arr[n][n], sum = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
			if (!(i - j && n - i - j - 1) && prime(arr[i][j])) sum += arr[i][j];
		};
	printf("%d\n", sum);
	return 0;
}
