/*
Cho số nguyên dương N.
Hãy tính S = 1 + 2 + ... + N

Dữ liệu vào:
Dòng đầu ghi số bộ test, không quá 10
Mỗi dòng ghi một số nguyên dương N, không quá 109

Kết quả:
Với mỗi test, ghi kết quả trên một dòng.

Ví dụ:
Input:
2
10
20

Output:
55
210
*/

#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned long n;
		scanf("%lu", &n);

		printf("%llu\n", (unsigned long long)n * (n + 1) / 2);
	}

	return 0;
}
