/*
Nhập vào số nguyên dương n không quá 30.

In ra màn hình n số đầu tiên thuộc dãy Fibonacci (tính từ số 0).

Input:
Chỉ có một dòng ghi số n.

Output:
Ghi ra kết quả tính toán trên một dòng

Ví dụ:
Input:
8

Output:
0 1 1 2 3 5 8 13
*/

#include <stdio.h>

int main(void) {
	long a = 0, b = 1;
	int n;
	scanf("%d", &n);
	while (n-- > 0) {
		printf("%ld ", a);
		long tmp = a;
		a = b;
		b += tmp;
	}
	putchar('\n');
	return 0;
}
