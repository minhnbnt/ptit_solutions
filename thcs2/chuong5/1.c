#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n], b = 0, c = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2) c++;
		else b++;
	};
	printf("%d %d\n", b, c);
	return 0;
}
