/*
Viết chương trình nhập một ma trận số nguyên dương cỡ M*N với 2<N,M<10, các số
không quá 100. Hãy in ra chuyển vị của ma trận đó.

Dữ liệu vào
Mỗi bộ test viết trên một dòng hai số N và M lần lượt là số hàng và số cột của
ma trận (2<N,M<10). Tiếp thep là N dòng ghi các số của ma trận.

Kết quả
In ra ma trận chuyển vị tương ứng.

Ví dụ:
Input:
2 3
1 2 4
3 4 0

Output:
1 3
2 4
4 0
*/

#include <stdio.h>

int main() {
	int a, b, i, j;
	scanf("%d %d", &a, &b);
	int arr[a][b];
	for (i = 0; i < a; i++)
		for (j = 0; j < b; j++) {
			scanf("%d", &arr[i][j]);
		}
	for (i = 0; i < b; i++) {
		for (j = 0; j < a; j++) {
			printf("%d ", arr[j][i]);
		}
		putchar('\n');
	}
	return 0;
}
