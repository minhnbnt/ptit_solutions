/*
Viết chương trình C cho phép nhập vào mảng A gồm n phần tư (1<n<100). Thực hiện
sắp xếp tăng dần các phần tử của mảng theo thuật toán chọn và In ra.

Trong đó:
INPUT
Hàng thứ nhất là số phần tử n của mảng A
Hàng thứ hai là các phần tử của mảng A

OUTPUT
Kết quả các bước sắp xếp theo thuật toán

INPUT:
5
64 25 12 22 11

OUTPUT:
11 25 12 22 64
11 12 25 22 64
11 12 22 25 64
11 12 22 25 64
*/

#include <stdio.h>

int main() {
	unsigned ele, i, j;
	scanf("%u", &ele);
	int arr[ele];
	for (i = 0; i < ele; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < ele - 1; i++) {
		int *min = &arr[i];
		for (j = i + 1; j < ele; j++)
			if (arr[j] < *min) min = &arr[j];
		int temp = arr[i];
		arr[i] = *min;
		*min = temp;
		for (j = 0; j < ele; j++) {
			printf("%d ", arr[j]);
		}
		putchar('\n');
	}
	return 0;
}
