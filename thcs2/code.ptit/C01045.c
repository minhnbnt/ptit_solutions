/*
Viết chương trình nhập vào một số nguyên dương N không quá 9 chữ số.

In ra chữ số đầu tiên và cuối cùng của N.

Input
Chỉ có một số nguyên dương N không quá 9 chữ số.

Output
Ghi ra kết quả trên một dòng

Ví dụ

Input:
1234

Output:
1 4
*/

#include <stdio.h>

int main() {
	unsigned long n;
	scanf("%lu", &n);
	char last = n % 10, first;
	while (n) {
		first = n % 10;
		n /= 10;
	};
	printf("%d %d\n", first, last);
	return 0;
}
