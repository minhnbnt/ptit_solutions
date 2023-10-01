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
DDDD
CDDD
BCDD
ABCD

Input:
3 5

Output:
CDEEE
BCDEE
ABCDE

Input:
5 3

Output:
CCC
CCC
CCC
BCC
ABC
*/

#include <stdio.h>

int main() {
	int a, b, i;
	scanf("%d %d", &a, &b);
	for (i = a - 1; i >= 0; i--) {
		int c = i, j = b;
		while (c < b) {
			putchar('A' + c++);
			j--;
		};
		while (j--) putchar('A' + b - 1);
		printf("\n");
	};
	return 0;
}
