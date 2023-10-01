#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n], odd[n], even[n];
	int odd_count = 0, even_count = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2) odd[odd_count++] = a[i];
		else even[even_count++] = a[i];
	};
	for (int i = 0; i < even_count; i++) printf("%d ", even[i]);
	printf("\n");
	for (int i = 0; i < odd_count; i++) printf("%d ", odd[i]);
	printf("\n");
	return 0;
}
