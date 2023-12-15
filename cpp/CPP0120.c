/*
Cho bốn số M, N, A, B. Nhiệm vụ của bạn là hãy đếm tất cả các số trong khoảng [M, N] chia hết cho
các số A, B.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test gồm 4 số M, N, A, B.
T, M, N, A, B thỏa mãn rang buộc 1≤T≤100; 1≤M, N ≤105; 1≤A, B ≤500;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
5 11 4 6
3 1000 5 9

Output:
2
289
*/

#include <stdio.h>

#define i64 long long

i64 gcd(i64 a, i64 b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		i64 m, n, a, b, i;
		scanf("%lld%lld%lld%lld", &m, &n, &a, &b);

		if (m > n) {
			i64 tmp = m;
			m = n, n = tmp;
		}

		unsigned long long result = 0;

		for (i64 i = m; i <= n; ++i)
			if (i % a == 0 || i % b == 0) {
				++result;
			}

		printf("%llu\n", result);
		fflush(stdout);
	}

	return 0;
}
