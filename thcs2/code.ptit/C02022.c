/*
Nhập vào chiều cao tam giác (không quá 9).
Vẽ hình tam giác số theo nguyên tắc tương ứng theo mẫu trong ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi chiều cao (không quá 9).

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
4

Output:
1
3 2
4 5 6
10 9 8 7
*/

#include <stdio.h>

int main() {
	unsigned n, i, j;
	scanf("%u", &n);
	unsigned num = 0;
	for (i = 1; i <= n; i++) {
		if (i % 2)
			for (j = 0; j < i; j++) //
				printf("%u ", ++num);
		else {
			unsigned temp = num += i;
			for (j = 0; j < i; j++) {
				printf("%u ", temp--);
			}
		}
		putchar('\n');
	}
	return 0;
}
