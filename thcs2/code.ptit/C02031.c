/*
Nhập vào chiều cao tam giác (không quá 20).

Vẽ hình tam giác ký tự theo nguyên tắc tương ứng theo mẫu trong ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi chiều cao (không quá 20).

Output
Ghi ra kết quả theo mẫu.

Ví dụ

Input:
5

Output:
DEFGH
CDEF
BCD
AB
@
*/

#include <stdio.h>

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = n - 1; i >= 0; i--) {
		char c = '@' + i;
		for (j = 0; j <= i; j++) //
			putchar(c + j);
		putchar('\n');
	};
	return 0;
}
