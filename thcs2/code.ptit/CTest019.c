/*
Cho ma trận A có kích thước N*M chỉ bao gồm các số nguyên có giá trị tuyệt đối
không quá 10000. Hãy sắp xếp cột thứ i của ma trận theo thứ tự từ nhỏ đến lớn và
in kết quả ra màn hình.

Chú ý: thứ tự cột sẽ tính từ 1 đến M

Input:
Dòng đầu ghi số bộ test (không quá 20).
Mỗi bộ test viết trên 2 dòng:

Dòng đầu ghi 3 số N, M, i
Dòng thứ 2 ghi các số trong ma trận lần lượt từ hàng 1 đến hàng N. Các số cách
nhau một khoảng trống Các ràng buộc: 2 ≤  N, M  ≤ 100; 1 ≤ i ≤  M;  0 ≤ ∣A[i,j]
∣ ≤ 10000)

Output:
Với mỗi bộ test, ghi ra N dòng của ma trận đã sắp xếp.

Ví dụ:
Input:
1
2 2 1
90 49
85 88

Output:
85 49
90 88
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { //
	return *(int *)a > *(int *)b;
}

int main(void) {
	unsigned n;
	scanf("%u", &n);
	int row, col, index, i, j;
	while (n--) {
		scanf("%d %d %d", &row, &col, &index);
		int arr[col][row];
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++) {
				scanf("%d", &arr[j][i]);
			}
		qsort(arr[--index], row, sizeof(int), cmp);
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++) {
				printf("%d ", arr[j][i]);
			}
			putchar('\n');
		}
	}
	return 0;
}
