/*
Viết chương trình nhập vào chiêu cao của tam giác (không quá 100) và thực hiện
in ra tam giác vuông theo mẫu trong ví dụ.

Input
Chỉ có một số dòng ghi chiều cao (không quá 100).

Output
Ghi ra kết quả theo mẫu.

Ví dụ
Input
5

Output
~~~~*
~~~**
~~***
~****
*****

*/

#include <stdio.h>

int main() {
	unsigned a, i, j;
	scanf("%u", &a);
	for (i = 1; i <= a; i++) {
		for (j = 1; j <= a - i; j++) {
			putchar('~');
		}
		for (j = 1; j <= i; j++) {
			putchar('*');
		}
		putchar('\n');
	}
	return 0;
}
