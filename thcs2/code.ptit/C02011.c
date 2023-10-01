/*
Nhập vào số hàng và số cột của hình chữ nhật (không quá 9). Vẽ hình chữ nhật số
theo nguyên tắc tương ứng theo mẫu trong các ví  dụ dưới đây.

Input
Chỉ có một số dòng ghi số hàng và số cột của hình chữ nhật (không quá 9).

Output
Ghi ra kết quả theo mẫu.

Ví dụ
Input:
4 4

Output:
1234
2343
3432
4321
---
Input:
3 5

Output:
12345
23454
34543
---
Input:
5 3

Output:
123
232
321
432
543
*/

#include <stdio.h>

int main() {
	int a, b, i;
	scanf("%d %d", &a, &b);
	for (i = 0; i < a; i++) {
		int num = i, j = 0;
		while (++num < b) {
			printf("%d", num);
			j++;
		};
		while (j++ < b) {
			printf("%d", num--);
		}
		putchar('\n');
	};
	return 0;
}
