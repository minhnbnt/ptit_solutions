#include <math.h>
#include <stdio.h>

int main() {
	int a, result = 1;
	scanf("%d", &a);
	for (int i = 2; i < sqrt(a); i++)
		if (!(a % i)) {
			result = 0;
			break;
		};
	printf("%d\n", result);
	return 0;
}
