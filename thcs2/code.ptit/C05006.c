/*
Viết chương trình  nhập vào ma trận nguyên dương cấp M*N (không quá 50). Chuyển
đổi hai hàng a và b trong ma trận và in ra kết quả.

INPUT
- Hàng thứ nhất là cấp m,n của ma trận
- m hàng tiếp theo là các phần tử của ma trận
- Hàng cuối cùng là giá trị a,b. Là các hàng cần chuyển đổi

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
7 8 9
4 5 6
1 2 3
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	unsigned row, col, i, j;
	scanf("%u %u", &row, &col);
	int **arr = malloc(sizeof(int *) * row);
	for (i = 0; i < row; i++) {
		arr[i] = malloc(sizeof(int) * col);
		for (j = 0; j < col; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	unsigned row1, row2;
	scanf("%u %u", &row1, &row2);
	int *temp = arr[--row1];
	arr[row1] = arr[--row2];
	arr[row2] = temp;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			printf("%d ", arr[i][j]);
		}
		putchar('\n'), free(arr[i]);
	}
	free(arr);
	return 0;
}
