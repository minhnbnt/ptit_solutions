/*
Viết chương trình phân tích một số nguyên thành các thừa số nguyên tố.

Input
Dòng đầu ghi số bộ test, mỗi bộ test ghi trên một dòng số nguyên dương cần phân
tích (không quá 9 chữ số) .

Output
Kết quả của mỗi bộ test ghi trên một dòng, mỗi thừa số cách nhau một khoảng
trống.

Ví dụ

Input:
2
10
20

Output:
2 5
2 2 5
*/

#include <math.h>
#include <stdio.h>

int main() {
	unsigned n;
	scanf("%u", &n);
	while (n--) {
		long x;
		scanf("%ld", &x);
		for (int i = 2; i <= sqrt(x); i++)
			while (x % i == 0) {
				x /= i;
				printf("%d ", i);
			}
		if (x > 1) printf("%ld", x);
		putchar('\n');
	}
	return 0;
}
