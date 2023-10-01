/*
Nhập vào chiều cao tam giác (không quá 9).

Vẽ hình tam giác số theo nguyên tắc tương ứng theo mẫu trong ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi chiều cao (không quá 9).

Output
Ghi ra kết quả theo mẫu.

Ví dụ
Input:
5

Output:
1
123
12345
1234567
123456789
*/

#include <stdio.h>

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < i * 2 + 1; j++) {
			printf("%d", j + 1);
		}
		putchar('\n');
	};
	return 0;
}
