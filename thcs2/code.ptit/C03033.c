/*
Hãy phân tích một số nguyên dương thành tích các thừa số nguyên tố.

Input
Dòng đầu tiên ghi số bộ test. Mỗi bộ test viết trên một dòng số nguyên dương n
không quá 9 chữ số.

Output
Mỗi bộ test viết ra kết quả phân tích theo mẫu như trong ví dụ (chú ý: giữa các
số với dấu * có một khoảng trống.

Ví dụ:
Input:
3
60
128
10000

Output:
60 = 2^2 * 3^1 * 5^1
128 = 2^7
10000 = 2^4 * 5^4
*/

#include <math.h>
#include <stdio.h>

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned long x, i;
		scanf("%lu", &x);
		printf("%lu = ", x);
		for (i = 2; i < sqrt(x); i++) {
			unsigned exp = 0;
			while (x % i == 0) x /= i, exp++;
			if (exp > 0) {
				printf("%lu^%u", i, exp);
				if (x > 1) printf(" * ");
			}
		}
		if (x > 1) printf("%ld^1", x);
		putchar('\n');
	}
	return 0;
}
