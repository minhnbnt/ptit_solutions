/*
Viết chương trình nhập vào số hàng và cột của hình bình hành (không quá 100).
Thực hiện in ra hình bình hành ngược theo mẫu trong ví dụ.

Input
Chỉ có một số dòng ghi hai số a,b là số hàng và số cột (không quá 100).

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
3 5

Output:
*****
~*****
~~*****

*/

#include <stdio.h>

int main() {
	unsigned a, b, i, j;
	scanf("%u%u", &a, &b);
	for (i = 0; i < a; i++) {
		for (j = 0; j < i; j++) {
			putchar('~');
		}
		for (j = 1; j <= b; j++) {
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}
