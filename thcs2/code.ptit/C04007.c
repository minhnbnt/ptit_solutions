/*
Viết chương trình nhập vào mảng A một chiều n phần tử (1 < n < 100) và mảng B
một chiều m phần tử (1 < m < 100). Thực hiện chèn mảng B vào mảng A tại vị trí P
và in ra mảng kết quả.

Input
Dòng thứ nhất là số phần tử của mảng A và mảng B
Dòng thứ hai là các phần tử của mảng A
Dòng thứ ba là các phần tử của mảng B
Dòng thứ tư là vị trí chèn

Các phần tử không vượt quá 1000. Vị trí cần chèn đảm bảo nằm trong mảng A.

Output
Ghi ra dãy kết quả trên một dòng.

Ví dụ:
Input:
5 3
1 2 3 4 5
6 7 8
3

Output:
1 2 3 6 7 8 4 5
*/

#include <stdio.h>

int main() {
	int a, b, i, j;
	scanf("%d %d", &a, &b);
	int arr1[a], arr2[b], pos;
	for (i = 0; i < a; i++) {
		scanf("%d", &arr1[i]);
	}
	for (j = 0; j < b; j++) {
		scanf("%d", &arr2[j]);
	}
	scanf("%d", &pos);
	char flag = 1;
	for (i = 0; i < a; i++) {
		if (pos - i == 0) {
			for (j = 0; j < b; j++) {
				printf("%d ", arr2[j]);
			}
			flag = 0;
		}
		printf("%d ", arr1[i]);
	}
	if (flag)
		for (j = 0; j < b; j++) //
			printf("%d ", arr2[j]);
	putchar('\n');
	return 0;
}
