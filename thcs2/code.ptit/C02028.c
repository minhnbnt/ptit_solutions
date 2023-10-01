/*
Nhập vào chiều cao tam giác (không quá 20).

Vẽ hình tam giác ký tự theo nguyên tắc tương ứng theo mẫu trong ví dụ dưới đây.

Input
Chỉ có một số dòng ghi chiều cao (không quá 20).

Output
Ghi ra kết quả theo mẫu.

Ví dụ
Input:
4

Output:
ACEG
CEG
EG
G
*/

#include <stdio.h>

int main() {
	int n, i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		char c = 'A' + i * 2;
		for (j = 0; j < n - i; j++) {
			putchar(c + 2 * j);
		}
		putchar('\n');
	};
	return 0;
}
