/*
Nhập vào chiều cao tam giác (không quá 20).
Vẽ hình tam giác ký tự theo nguyên tắc tương ứng theo mẫu trong ví dụ dưới đây.

Input
Chỉ có một số dòng ghi chiều cao (không quá 20).

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
4

Output:
A
B E
C F H
D G I J
*/

#include <stdio.h>

int main() {
	unsigned n, i, j;
	scanf("%u", &n);
	for (i = 0; i < n; i++) {
		char c = 'A' + i;
		unsigned interval = n;
		for (j = 0; j <= i; j++) {
			printf("%c ", c);
			c += --interval;
		}
		putchar('\n');
	}
	return 0;
}
