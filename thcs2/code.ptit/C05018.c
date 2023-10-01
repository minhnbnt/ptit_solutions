/*
Ma trận xoáy ốc ngược cấp N là ma trận vuông có N*N phần tử. Các số được điền
vào ma trận trận theo chiều kim đồng hồ theo thứ tự giảm dần về 1.

Dữ liệu vào
Dòng 1 ghi số bộ test
Mỗi bộ test ghi số N (1<N<20).

Kết quả
Ghi ra thứ tự bộ test và ma trận xoáy ốc ngược tương ứng

Ví dụ:
Input:
1
3

Output:
Test 1:
9 8 7
2 1 6
3 4 5
*/

#include <stdio.h>

char x[4] = { 1, 0, 0, -1 };
char y[4] = { 0, 1, -1, 0 };

int main(void) {
	unsigned test, i = 0;
	scanf("%u", &test);
	while (i++ < test) {
		printf("Test %u:\n", i);
		unsigned n, i, j, k;
		scanf("%u", &n);
		int a[n + 1][n + 2], num = n * n;
		for (i = 0; i <= n; i++)
			for (j = 0; j <= n + 1; j++) a[i][j] = 0;
		for (i = 0; i <= n; i++) {
			a[i][0] = a[i][n + 1] = a[n][i] = 1;
		}
		i = j = k = 0;
		while (num > 0) {
			while (a[i + y[k]][j + x[k]] == 0) {
				i += y[k], j += x[k];
				a[i][j] = num--;
			}
			if (++k == 4) k = 0;
		}
		for (i = 0; i < n; i++) {
			for (j = 1; j <= n; j++) {
				printf("%d ", a[i][j]);
			}
			putchar('\n');
		}
	}
	return 0;
}
