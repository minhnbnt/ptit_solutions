#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int arr[n], m;
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
	scanf("%d", &m);
	for (int i = 0; i < n; i++)
		if (m - i - 1) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
