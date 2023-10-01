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
ABCD
BCDA
CDBA
DCBA
---
Input:
3 5

Output:
ABCDE
BCDEA
CDEBA
---
Input:
5 3

Output:
ABC
BCA
CBA
CBA
CBA
*/

#include <stdio.h>

int main() {
	int a, b, i;
	scanf("%d %d", &a, &b);
	for (i = 0; i < a; i++) {
		int j = b, c = i;
		while (c < b) {
			putchar('A' + c++);
			j--;
		}
		while (j--) putchar('A' + j);
		printf("\n");
	}
	return 0;
}
