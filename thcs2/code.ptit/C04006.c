/*
Viết chương trình nhập vào mảng A gồm n phần tử (1 < n < 100). Thực hiện đảo
ngược mảng và in ra kết quả.

Input
Dòng thứ nhất là số phần tử của mảng A.
Dòng thứ hai là các phần tử của mảng A
Các phần tử không vượt quá 1000.

Output
Ghi ra dãy kết quả trên một dòng.

Ví dụ:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1
*/

#include <stdio.h>

int main() {
	int ele, i;
	scanf("%d", &ele);
	int arr[ele];
	for (i = 0; i < ele; i++) {
		scanf("%d", &arr[i]);
	}
	for (i = ele - 1; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
	putchar('\n');
	return 0;
}
