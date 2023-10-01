/*
Viết chương trình nhập vào mảng A gồm n phần tử (1 < n < 100). Thực hiện dịch n
phần tử của mảng sang phải và In ra mảng kết quả

Input
Dòng thứ nhất là số phần tử của mảng A.
Dòng thứ hai là các phần tử của mảng A
Dòng thứ 3 là số lượng phần tử cần dịch phải.

Các phần tử không vượt quá 1000.

Output
Ghi ra kết quả trên một dòng.

Ví dụ:

Input:
10
1 2 3 4 5 6 7 8 9 10
3

Output:
8 9 10 1 2 3 4 5 6 7
*/

#include <stdio.h>

int main() {
	unsigned ele, pos, i;
	scanf("%d", &ele);
	int arr[ele];
	for (i = 0; i < ele; i++) //
		scanf("%d", &arr[i]);
	scanf("%u", &pos);
	for (i = ele - pos; i < ele; i++) //
		printf("%d ", arr[i]);
	for (i = 0; i < ele - pos; i++) //
		printf("%d ", arr[i]);
	putchar('\n');
	return 0;
}
