/*
Viết chương trìnhnhập vào ma trận nguyên dương cấp M*N (không quá 50). Chuyển
đổi hai cột a và b trong ma trận và in ra kết quả.

INPUT
- Hàng thứ nhất là cấp m,n của ma trận
- m hàng tiếp theo là các phần tử của ma trận
- Hàng cuối cùng là vị trí cột cần chuyển đổi

OUTPUT
- Ma trận kết quả

Ví dụ:
Input:
3 3
1 2 3
4 5 6
7 8 9
1 3

Output:
3 2 1
6 5 4
9 8 7
*/

#include <stdio.h>

int main(void) {
	unsigned row, col, i, j;
	scanf("%u %u", &row, &col);
	int arr[row][col];
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	unsigned col1, col2;
	scanf("%u%u", &col1, &col2);
	--col1, --col2;
	for (i = 0; i < row; i++) {
		int tmp = arr[i][col1];
		arr[i][col1] = arr[i][col2];
		arr[i][col2] = tmp;
	}
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", arr[i][j]);
		}
		putchar('\n');
	}
	return 0;
}
