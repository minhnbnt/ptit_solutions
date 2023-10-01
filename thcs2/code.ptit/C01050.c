/*
Nhập vào kích thước chiều rộng, chiều cao và in ra hình chữ nhật các dấu * nhưng
rỗng bên trong. Các dấu * được in sát cạnh nhau.

Dữ liệu vào chỉ có 2 số nguyên dương là chiều rộng và chiều cao (không quá 40).

Ví dụ:
Input:
5 4

Output:
*****
*   *
*   *
*****
*/

#include <stdio.h>

int main() {
	unsigned a, b, i, j;
	scanf("%u %u", &a, &b);
	for (i = 0; i < b; i++) {
		for (j = 0; j < a; j++)
			if (i && j && i - b + 1 && j - a + 1) {
				putchar(' ');
			} else putchar('*');
		putchar('\n');
	}
	return 0;
}
