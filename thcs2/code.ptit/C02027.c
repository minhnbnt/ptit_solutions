/*
Nhập vào chiều cao tam giác (không quá 20).
Vẽ hình tam giác ký tự theo nguyên tắc tương ứng theo mẫu trong ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi chiều cao (không quá 20).

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
4

Output:
a
c b
d e f
j i h g
*/

#include <stdio.h>

int main() {
	unsigned n, i, j;
	scanf("%u", &n);
	unsigned num = 0;
	for (i = 1; i <= n; i++) {
		if (i % 2)
			for (j = 0; j < i; j++) //
				putchar('a' - 1 + ++num);
		else {
			unsigned temp = num += i;
			for (j = 0; j < i; j++) //
				putchar('a' - 1 + temp--);
		}
		putchar('\n');
	}
	return 0;
}
