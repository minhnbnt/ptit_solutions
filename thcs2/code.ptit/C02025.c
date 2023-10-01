/*
Nhập vào số hàng và số cột của hình chữ nhật (không quá 20). Vẽ hình chữ nhật ký
tự theo nguyên tắc tương ứng theo mẫu trong các ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi số hàng và số cột của hình chữ nhật (không quá 20).

Output
Ghi ra kết quả theo mẫu.

Ví dụ
Input:
4 4

Output:
@ABC
ABCC
BCCC
CCCC
---
Input:
3 5

Output:
@ABCD
ABCDD
BCDDD
---
Input:
5 3

Output:
@AB
ABB
BBB
BBB
BBB
*/

#include <stdio.h>

int main() {
	unsigned a, b, i;
	scanf("%u %u", &a, &b);
	for (i = 0; i < a; i++) {
		unsigned c = i, j = b;
		while (c < b && j > 0) {
			putchar('@' + c++);
			j--;
		};
		c = b - 1;
		while (j-- > 0) putchar('@' + c);
		putchar('\n');
	};
	return 0;
}
