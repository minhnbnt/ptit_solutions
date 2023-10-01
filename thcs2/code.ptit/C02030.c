/*
Nhập vào chiều cao tam giác (không quá 20).
Vẽ hình tam giác ký tự theo nguyên tắc tương ứng theo mẫu trong ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi chiều cao (không quá 20).

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
5

Output:
@
@B@
@BDB@
@BDFDB@
@BDFHFDB@
*/

#include <stdio.h>

int main() {
	unsigned n, i, j;
	scanf("%u", &n);
	for (i = 1; i <= n; i++) {
		char c = '@' - 2;
		for (j = 0; j < i; j++) {
			putchar(c += 2);
		}
		for (j = 1; j < i; j++) {
			putchar(c -= 2);
		}
		putchar('\n');
	}
	return 0;
}
