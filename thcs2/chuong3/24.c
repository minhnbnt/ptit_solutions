#include <math.h>
#include <stdio.h>

int prime(int n) {
	if (n == 1) return 2;
	int num = 2;
	while (n != 1) {
		int flag = 1;
		num++;
		for (int j = 2; j <= sqrt(num); j++)
			if (!(num % j)) {
				flag = 0;
				break;
			}
		if (flag) n--;
	};
	return num;
}

int main() {
	int i = 1, num;
	scanf("%d", &num);
	while (prime(i) <= num) {
		printf("%d ", prime(i));
		i++;
	};
	printf("\n");
	return 0;
}
