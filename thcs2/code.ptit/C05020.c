/*
Ma trận xoáy ốc Fibonacci cấp N là ma trận vuông có N*N phần tử. Các số được
điền vào ma trận theo chiều kim đồng hồ đều là các số thuộc dãy Fibonacci từ nhỏ
đến lớn (tính từ số 0).

Viết chương trình nhập N (không quá 9) và in ra ma trận xoắn ốc Fibonacci tương
ứng.

Ví dụ:
Input:
3

Output:
0 1 1
13 21 2
8 5 3
*/

#include <stdio.h>

char x[4] = { 1, 0, 0, -1 };
char y[4] = { 0, 1, -1, 0 };

int main(void) {
	unsigned n, i, j, k;
	scanf("%u", &n);
	unsigned long long a[n + 1][n + 2], num = n * n;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n + 1; j++) a[i][j] = 0;
	for (i = 0; i <= n; i++) {
		a[i][0] = a[i][n + 1] = a[n][i] = 1;
	}
	i = j = k = 0;
	unsigned long long fib1 = 0, fib2 = 1;
	while (num > 0) {
		while (a[i + y[k]][j + x[k]] == 0) {
			if (1 == i == j && k) break;
			i += y[k], j += x[k];
			a[i][j] = fib1, --num;
			unsigned long long tmp = fib1;
			fib1 = fib2, fib2 += tmp;
		}
		if (++k == 4) k = 0;
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%lld ", a[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
