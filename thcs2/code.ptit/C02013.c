/*
Nhập vào số hàng và số cột của hình chữ nhật (không quá 9). Vẽ hình chữ nhật số
theo nguyên tắc tương ứng theo mẫu trong các ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi số hàng và số cột của hình chữ nhật (không quá 9).

Output
Ghi ra kết quả theo mẫu.

Ví dụ
Input
4 4

Output:
4321
3212
2123
1234
---
Input:
4 6

Output:
654321
543212
432123
321234

Input:
6 4

Output:
6543
5432
4321
3212
2123
1234
*/

#include <stdio.h>

int main() {
	unsigned a, b, i, k;
	scanf("%u %u", &a, &b);
	k = (a > b) ? a : b;
	for (i = 0; i < a; i++) {
		unsigned num = k - i, j = b;
		while (num && j > 0) {
			printf("%u", num--);
			j--;
		}
		num = 1;
		while (j > 0) {
			printf("%u", ++num);
			j--;
		}
		putchar('\n');
	}
	return 0;
}
