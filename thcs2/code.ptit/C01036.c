/*
Cho một số nguyên dương N.

Thực hiện tìm tích của các chữ số và in ra màn hình.

Input
Chỉ có một dòng ghi số nguyên dương N (không quá 9 chữ số)

Output
Ghi ra kết quả trên một dòng

Ví dụ
Input:
1234

Output:
24
*/

#include <stdio.h>

int main() {
	unsigned long n, result = 1;
	scanf("%lu", &n);
	do result *= n % 10;
	while (n /= 10);
	printf("%lu\n", result);
	return 0;
}
