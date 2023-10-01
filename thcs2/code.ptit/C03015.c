/*
Cho số nguyên dương N. Hãy đưa ra ước số nguyên tố lớn nhất của N.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test ghi số nguyên dương N.
T, N thỏa mãn ràng buộc: 1≤T≤100; 2≤N≤10^10.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:

Input:
2
315
31

Output:
7
31
*/

#include <math.h>
#include <stdio.h>

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		char flag = 1;
		unsigned long a, tmp;
		unsigned b, i;
		scanf("%lu", &a);
		for (i = 2; i <= sqrt(a); i++)
			while (a % i == 0) a /= i, b = i;
		if (a > 1) printf("%lu\n", a);
		else printf("%u\n", b);
	}
	return 0;
}
