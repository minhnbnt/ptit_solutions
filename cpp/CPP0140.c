/*
Cho số tự nhiên N. Nhiệm vụ của bạn là hãy kiểm tra N có phải là số hoàn hảo hay không. Một số N
được gọi là số hoàn hảo nếu tổng các ước số của nó bằng chính nó.

Ví dụ N = 6=1 + 2 + 3 là số hoàn
hảo.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên N.

T, N thỏa mãn rang buộc 1≤T≤100; 1≤N≤10^18.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
6
21

Output:
1
0
*/

#include <math.h>
#include <stdio.h>

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		unsigned long long N;
		scanf("%llu", &N);

		if (N > (unsigned long long)1e12) {

			puts("0");
			fflush(stdout);

			continue;
		}

		unsigned long long sum = 1;
		for (unsigned i = 2; i < sqrt(N); ++i) {
			if (N % i == 0) {
				sum += i;
				sum += N / i;
			}
		}

		const int isqrt = sqrt(N);
		if (isqrt * isqrt == N) {
			sum += isqrt;
		}

		printf("%d\n", sum == N);
		fflush(stdout);
	}

	return 0;
}
