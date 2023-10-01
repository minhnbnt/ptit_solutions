/*
Viết chương trình nhập vào mảng A gồm n phần tử (1 < n < 100). Thực hiện sắp xếp
tăng dần các phần tử của mảng và in ra màn hình.

Input
Dòng thứ nhất là số phần tử của mảng A.
Dòng thứ hai là các phần tử của mảng A
Các phần tử không vượt quá 1000.

Output
Ghi ra kết quả trên một dòng.

Ví dụ:
Input:
8
1 3 8 2 9 7 6 5

Output:
1 2 3 5 6 7 8 9
*/

#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { //
	return *(int *)a - *(int *)b;
};

int main() {
	unsigned n, i, j;
	scanf("%u", &n);
	int arr[n];
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	qsort(arr, n, sizeof(int), cmp);
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
	return 0;
}
