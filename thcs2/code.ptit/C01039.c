/*
Cho số nguyên dương N không quá 9 chữ số.

Hãy đếm xem N có bao nhiêu chữ số.

Input
Chỉ có một số nguyên dương N không quá 9 chữ số.

Output
Ghi ra kết quả trên một dòng

Ví dụ:
Input:
1234

Output:
4
*/

#include <stdio.h>

int main() {
	long n;
	scanf("%ld", &n);
	char digits = 0;
	do ++digits;
	while (n /= 10);
	printf("%d\n", digits);
	return 0;
}
