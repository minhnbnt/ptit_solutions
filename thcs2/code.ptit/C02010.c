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
2341
3421
4321
---
Input:
3 5

Output:
12345
23451
34521
---
Input:
6 4

Output:
1234
2341
3421
4321
5321
6321
*/

#include <stdio.h>

int main() {
	int a, b, i, j;
	scanf("%d %d", &a, &b);
	for (i = 1; i <= a; i++) {
		for (j = i; j <= b; j++) {
			printf("%d", j);
		}
		if (i > b) {
			printf("%d", i);
			j = b;
		} else j = i;
		while (--j) printf("%d", j);
		putchar('\n');
	};
	return 0;
}
