/*
Ma trận xoắn ốc cấp N là một ma trận vuông cấp N*N trong đó ghi các số nguyên
dương tăng dần từ 1 đến N*N được điền theo thứ tự xoắn ốc từ ngoài vào trong.

Hãy viết chương trình in ra ma trận xoắn ốc cấp N.

Input:
Chỉ có một dòng ghi số N (1 ≤ N ≤ 100)

Ouput:
Ghi ra ma trận kết quả có N dòng, mỗi giá trị số cách nhau một khoảng trống.

Ví dụ:
Input:
5

Output:
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/

#include <stdio.h>

char x[4] = { 1, 0, 0, -1 };
char y[4] = { 0, 1, -1, 0 };

int main(void) {
	unsigned n, i, j, k;
	scanf("%u", &n);
	int a[n + 1][n + 2], num = 0;
	for (i = 0; i <= n; i++)
		for (j = 0; j <= n + 1; j++) a[i][j] = 0;
	for (i = 0; i <= n; i++) {
		a[i][0] = a[i][n + 1] = a[n][i] = 1;
	}
	i = j = k = 0;
	while (num < n * n) {
		while (a[i + y[k]][j + x[k]] == 0) {
			i += y[k], j += x[k];
			a[i][j] = ++num;
		}
		if (++k == 4) k = 0;
	}
	for (i = 0; i < n; i++) {
		for (j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
