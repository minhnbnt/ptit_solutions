#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n], arr[n];
	for (int i = 0; i < n; i++) {
		a[i] = 0;
		scanf("%d", &arr[i]);
		for (int j = 0; j < i; j++)
			if (arr[i] == arr[j]) {
				a[j] = 1;
				break;
			};
	};
	for (int i = 0; i < n; i++)
		if (a[i]) printf("%d ", arr[i]);
	printf("\n");
	return 0;
}
