/*
Nhập vào một số n không quá 8 chữ số và kiểm tra số đó có thuộc dãy Fibonacci
hay không. Nếu thỏa mãn in ra 1, ngược lại in ra 0.

Input:
Chỉ có một số nguyên dương, không quá 8 chữ số.

Output:
In ra kết quả kiểm tra

Ví dụ:
Input:
8

Output:
1
*/

#include <stdio.h>

int main(void) {
	long n, a, b;
	scanf("%ld", &n);
	a = 0, b = 1;
	while (a < n) {
		long tmp = a;
		a = b;
		b += tmp;
	}
	printf("%d\n", a == n);
	return 0;
}
