#include <math.h>
#include <stdio.h>

int prime(int n) {
	int num = 2;
	if (n == 1) return num;
	while (n != 1) {
		num++;
		int flag = 1;
		for (int i = 2; i <= sqrt(num); i++)
			if (!(num % i)) {
				flag = 0;
				break;
			};
		if (flag) n--;
	};
	return num;
}

int main() {
	int i = 1, n, sum = 0;
	scanf("%d", &n);
	while (prime(i) <= n) {
		sum += prime(i);
		i++;
	};
	printf("%d\n", sum);
	return 0;
}
