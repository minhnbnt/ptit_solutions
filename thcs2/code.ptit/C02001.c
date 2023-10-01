/*
Viết chương trình nhập vào n là cạnh của hình vuông và in ra hình vuông các ký
tự *. Giá trị n không quá 100.

Input
Chỉ có một số nguyên dương N không quá 100.

Output
Ghi ra kết quả theo mẫu.

Ví dụ:
Input:
4

Output:
****
****
****
****

*/

#include <stdio.h>

int main() {
	unsigned n, i, j;
	scanf("%u", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) putchar('*');
		putchar('\n');
	}
	return 0;
}
