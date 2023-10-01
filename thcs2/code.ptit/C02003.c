/*
Viết chương trình nhập vào n (không quá 100) là cạnh của hình vuông và thực hiện
in ra hình vuông rỗng các ký tự * theo mẫu trong ví dụ.

Input
Chỉ có một số nguyên dương N không quá 100.

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
4

Output:
****
*..*
*..*
****

*/

#include <stdio.h>

int main() {
	unsigned n, i, j;
	scanf("%u", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			if (i == 1 || j == 1 || //
			    i == n || j == n) {
				putchar('*');
			} else putchar(' ');
		printf("\n");
	}
	return 0;
}
