/*
Cho số nguyên dương N. Hãy đưa ra tất cả các ước số nguyên tố của N.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào T bộ test. Mỗi bộ test là  một số nguyên dương N được
ghi trên một dòng. T, N thỏa mãn ràng buộc: 1≤T≤100; 2≤N≤1010.

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Input:
2
315
31

Output:
3 3 5 7
31
*/

#include <math.h>
#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned long long n;
		scanf("%llu", &n);

		for (unsigned long i = 2; i <= sqrt(n); ++i)
			while (n % i == 0) {
				n /= i;
				printf("%lu ", i);
			}
		if (n > 1) printf("%llu ", n);
		putchar('\n'), fflush(stdout);
	}

	return 0;
}
