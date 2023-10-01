/*
Nhập vào số hàng và số cột của hình chữ nhật (không quá 20). Vẽ hình chữ nhật ký
tự theo nguyên tắc tương ứng theo mẫu trong các ví  dụ dưới đây.

Input

Chỉ có một số dòng ghi số hàng và số cột của hình chữ nhật (không quá 20).

Output

Ghi ra kết quả theo mẫu.

Ví dụ
Input:
5 5

Output:
eeeee
edddd
edccc
edcbb
edcba
---
Input:
4 6

Output:
ffffff
feeeee
fedddd
fedccc
---
Input:
6 4

Output:
ffff
feee
fedd
fedc
fedc
fedc
*/

#include <stdio.h>

int main() {
	unsigned a, b, i, j, k;
	scanf("%d %d", &a, &b);
	k = (a > b) ? a : b;
	for (i = 0; i < a; i++) {
		char c = k - 1 + 'a';
		for (j = 0; j < b; j++) {
			putchar((j < i) ? c-- : c);
		};
		putchar('\n');
	};
	return 0;
}
