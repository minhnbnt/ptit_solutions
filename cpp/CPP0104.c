/*
Viết chương trình tính tổng  S = 1 + 1.2 + 1.2.3 + ...+ 1.2.3...N

Input:
Dữ liệu vào chỉ có 1 dòng ghi số N không quá 20.

Output:
Kết quả ghi trên một dòng.

Ví dụ:
Input:
3

Output:
9
*/

#include <stdio.h>

int main(void) {

	unsigned n, i;
	scanf("%u", &n);

	unsigned long long sum = 0, prev = 1;

	for (i = 1; i <= n; i++) {
		prev *= i;
		sum += prev;
	}

	printf("%llu\n", sum);

	return 0;
}
