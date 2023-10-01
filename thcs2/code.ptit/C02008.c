/*
Viết chương trình nhập vào chiều cao của tam giác (không quá 100) và In ra tam
giác hình sao rỗng tương ứng theo mẫu trong ví dụ.

Input
Chỉ có một số dòng ghi chiều cao (không quá 100).

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
5

Output:
*
**
*.*
*..*
*****

*/

#include <stdio.h>

int main() {
	unsigned a, i, j;
	scanf("%u", &a);
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= i; j++)
			if (j == 1 || j == i || //
			    i == a || j == i) {
				putchar('*');
			} else putchar('.');
		putchar('\n');
	}
	return 0;
}
