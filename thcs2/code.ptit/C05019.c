/*
Ma trận xoắn ốc nguyên tố cấp N là ma trận vuông có N*N phần tử. Các số được
điền vào ma trận theo chiều kim đồng hồ đều là các số nguyên tố từ nhỏ đến lớn.

Dữ liệu vào:
Dòng 1 ghi số bộ test
Mỗi bộ test ghi số N (1<N<20).

Kết quả:
Ghi ra thứ tự bộ test và ma trận xoắn ốc nguyên tố tương ứng

Ví dụ:

Input
1
3

Output:
Test 1:
 2  3  5
19 23  7
17 13 11
*/

#include <math.h>
#include <stdio.h>

char prime[1000];
char x[4] = { 1, 0, 0, -1 };
char y[4] = { 0, 1, -1, 0 };

void sieve(void) {
	prime[0] = prime[1] = 0;
	unsigned i, j;
	for (i = 2; i < 1000; i++) prime[i] = 1;
	for (i = 2; i <= sqrt(1000); i++)
		if (prime[i])
			for (j = i * i; j < 1000; j += i) //
				prime[j] = 0;
}

int main(void) {
	sieve();
	unsigned test, i = 0;
	scanf("%u", &test);
	while (i++ < test) {
		printf("Test %u:\n", i);
		unsigned n, i, j, k;
		scanf("%u", &n);
		int a[n + 1][n + 2];
		for (i = 0; i <= n; i++)
			for (j = 0; j <= n + 1; j++) a[i][j] = 0;
		for (i = 0; i <= n; i++) {
			a[i][0] = a[i][n + 1] = a[n][i] = 1;
		}
		i = j = k = 0;
		unsigned num = 0;
		while (num < n * n) {
			while (a[i + y[k]][j + x[k]] == 0) {
				i += y[k], j += x[k];
				unsigned tmp = ++num, l = 0;
				while (tmp > 0) tmp -= prime[++l];
				a[i][j] = l;
			}
			if (++k == 4) k = 0;
		}
		for (i = 0; i < n; i++) {
			for (j = 1; j <= n; j++) {
				printf("%2d ", a[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}
