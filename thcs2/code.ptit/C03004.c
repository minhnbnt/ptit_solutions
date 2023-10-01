/*
Viết chương trình tìm ước số chung lớn nhất và bội số chung nhỏ nhất của hai số
nguyên dương a,b.

Input
Dữ liệu vào chỉ có 2 số nguyên dương a và b không quá 9 chữ số.

Ouput
Kết quả ghi trên 2 dòng, dòng đầu là USCLN, dòng thứ 2 là BSCNN.

Ví dụ
Input
2 5

Output
1
10
*/

#include <stdio.h>

long gcd(long a, long b) {
	if (!a) return b;
	return gcd(b % a, a);
}

void print(long a, long b) {
	long ucln = gcd(a, b);
	printf("%ld\n%lld\n", //
	       ucln, (long long)a * b / ucln);
}

int main(void) {
	long a, b;
	scanf("%ld %ld", &a, &b);
	print(a, b);
	return 0;
}
