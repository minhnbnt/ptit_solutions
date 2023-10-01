/*
Cho hai cặp số (a,b) và (c,d). Hãy tính toán xem ước số chung lớn nhất của hai
cặp số này có bằng nhau hay không.

Input
Dòng đầu ghi số bộ test
Mỗi bộ test ghi số 4 số a, b, c, d. Các số không quá 10^9

Output
Với mỗi bộ test, ghi ra YES nếu 2 cặp số (a,b) và (c,d) có ước chung lớn nhất
bằng nhau, ngược lại ghi ra NO trên một dòng.

Ví dụ:
Input:
2
2 4 4 8
3 5 7 9

Output:
NO
YES
*/

#include <stdio.h>

long gcd(long a, long b) {
	if (a == 0) return b;
	return gcd(b % a, a);
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		long a, b, c, d;
		scanf("%ld %ld", &a, &b);
		scanf("%ld %ld", &c, &d);
		puts(gcd(a, b) != gcd(c, d) ? "NO" : "YES");
	}
	return 0;
}
