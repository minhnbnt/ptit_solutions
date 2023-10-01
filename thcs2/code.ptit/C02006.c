/*
Viết chương trình nhập vào hàng và cột của hình bình hành (không quá 100). Thực
hiện in hình bình hành ngược và rỗng theo mẫu trong ví dụ.

Input
Chỉ có một số dòng ghi hai số a,b là số hàng và số cột (không quá 100).

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
3 4

Output:
****
~*..*
~~****

*/

#include <stdio.h>

int main() {
	unsigned a, b, i, j;
	scanf("%u %u", &a, &b);
	for (i = 1; i <= a; i++) {
		for (j = 1; j < i; j++) {
			putchar('~');
		}
		for (j = 1; j <= b; j++)
			if (i == 1 || j == 1 || //
			    i == a || j == b) {
				putchar('*');
			} else putchar('.');
		putchar('\n');
	}
	return 0;
}
