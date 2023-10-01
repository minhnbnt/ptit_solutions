/*
Viết chương trình tính tích hai ma trận A cỡ n*m và ma trận B cỡ m*p.

Với 1 < n,m,p < 50. Các giá trị trong ma trận đều nguyên dương và không vượt quá
1000.

Input
Dòng đầu ghi 3 số n,m,p
n dòng tiếp theo ghi ma trận A
m dòng tiếp theo ghi ma trận B

Output:
Ghi ra ma trận tích

Ví dụ
Input:
3 4 3
1 2 3 4
4 2 3 1
2 4 1 3
1 1 1
2 2 2
3 3 3
4 4 4

Output:
30 30 30
21 21 21
25 25 25
*/

#include <stdio.h>

int main(void) {

	size_t m, n, p, i, j, k;
	scanf("%lu%lu%lu", &n, &m, &p);

	int mx1[n][m], mx2[m][p];

	for (i = 0; i < n; ++i)
		for (j = 0; j < m; ++j) {
			scanf("%d", &mx1[i][j]);
		}
	for (i = 0; i < m; ++i)
		for (j = 0; j < p; ++j) {
			scanf("%d", &mx2[i][j]);
		}

	for (i = 0; i < n; ++i) {
		for (j = 0; j < p; ++j) {

			int result = 0;

			for (k = 0; k < m; ++k) {
				result += mx1[i][k] * mx2[k][j];
			}

			printf("%d ", result);
		}

		putchar(0xa);
	}

	fflush(stdout);

	return 0;
}
