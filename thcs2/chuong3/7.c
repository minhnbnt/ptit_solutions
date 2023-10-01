#include <stdio.h>

int main() {
	int a = 0, b = 0;
	long long int n;
	scanf("%lld", &n);
	while (n > 0) {
		if ((n % 10) % 2) b++;
		else a++;
		n /= 10;
	};
	printf("%d %d\n", a, b);
	return 0;
}
