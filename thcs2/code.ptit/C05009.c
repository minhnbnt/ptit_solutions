/*
Viết chương trình nhập vào ma trận vuông các số nguyên dương cấp M (không quá
50). Thực hiện chuyển đổi hai đường chéo của ma trận và in ra ma trận kết quả.

INPUT:
- Hàng thứ nhất là cấp m của ma trận
- m hàng tiếp theo là các phần tử của ma trận

OUTPUT:
- Ma trận kết quả

Ví dụ:
Input:
3
1 2 3
4 5 6
7 8 9

Output:
3 2 1
4 5 6
9 8 7
*/

#include <stdio.h>

int main(void) {
	unsigned rank, i, j;
	scanf("%u", &rank);
	int arr[rank][rank];
	for (i = 0; i < rank; i++)
		for (j = 0; j < rank; j++) //
			scanf("%d", &arr[i][j]);
	for (i = 0; i < rank; i++) {
		int tmp = arr[i][i];
		arr[i][i] = arr[i][rank - i - 1];
		arr[i][rank - i - 1] = tmp;
	}
	for (i = 0; i < rank; i++) {
		for (j = 0; j < rank; j++) //
			printf("%d ", arr[i][j]);
		putchar('\n');
	}
	return 0;
}
