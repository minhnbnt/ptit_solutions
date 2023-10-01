#include <stdio.h>

int main() {
	long int a;
	scanf("%ld", &a);
	long int temp = a;
	int i = 0, sum = 0;
	while (a) {
		a /= 10;
		i++;
	};
	a = temp;
	while (a) {
		int mul = 1;
		for (int k = 1; k <= i; k++) mul *= a % 10;
		sum += mul;
		a /= 10;
	};
	if (sum == temp) printf("1\n");
	else printf("0\n");
	return 0;
}
