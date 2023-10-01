#include <stdio.h>

int sum(int a) {
	int sum = 0;
	while (a > 0) {
		sum += a % 10;
		a /= 10;
	};
	return sum;
}

int check6(int a) {
	while (a > 0) {
		if (a % 10 == 6) return 1;
		a /= 10;
	}
	return 0;
}

int revertable(int a) {
	int arr[5];
	int count = 0;
	do {
		arr[count++] = a % 10;
		a /= 10;
	} while (a > 0);
	for (int i = 0; i < count / 2; i++) {
		if (arr[i] != arr[count - i - 1]) return 0;
	}
	return 1;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	for (int i = a; i <= b; i++)
		if (!(sum(i) % 7) && check6(i) && revertable(i)) printf("%d\n", i);
	return 0;
}
