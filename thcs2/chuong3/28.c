#include <stdio.h>

int isarmstrong(long int n) {
	long int temp = n;
	int sum = 0, i = 0;
	while (n > 0) {
		n /= 10;
		i++;
	};
	n = temp;
	while (n > 0) {
		int a = n % 10, num = 1;
		for (int j = 0; j < i; j++) num *= a;
		n /= 10;
		sum += num;
	};
	if (sum - temp) return 0;
	return 1;
}

int main() {
	long int n;
	scanf("%ld", &n);
	for (int i = 1; i < n; i++)
		if (isarmstrong(i)) printf("%d ", i);
	printf("\n");
	return 0;
}
