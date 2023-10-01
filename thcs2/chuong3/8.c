#include <stdio.h>

int fibonacci(int n) {
	if (n == 1 || n == 2) return 1;
	else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	int x = 1, flag = 1;
	while (flag) {
		int fib = fibonacci(x);
		if (fib >= a && fib <= b) printf("%d ", fib);
		else if (fib > b) flag = 0;
		x++;
	};
	printf("\n");
	return 0;
}
