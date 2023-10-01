/*
Cho hai số nguyên không âm N và K. Nhiệm vụ của bạn là kiểm tra xem K = 1%K +
2%K + ..+ N%K hay không. Đưa ra 1 hoặc 0 nếu cặp N, K thỏa mãn hoặc không thỏa
mãn yêu cầu bài toán.

Ví dụ với N = 10, K=55 ta có kết quả là 1 vì 55= 1%55 + 2%55+3%55 + ..+ 10%55.

Ngược lại, N=4, K=11 có kết quả là 0 vì 11 ≠ 1%11 + 2%11 + 3%11 +4%11.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là bộ đôi N, K được viết
cách nhau một vài khoảng trống. T, N, K thỏa mãn ràng buộc : 1≤T≤100; 0≤N ≤1000;
0≤K ≤1012.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
10 55
1 11

Output:
1
0
*/

#include <stdio.h>

#define u64 unsigned long long

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 N, K;
		scanf("%llu%llu", &N, &K);

		u64 n = N / K, S = N % K;

		u64 T = K * (K - 1) / 2 - K;
		u64 remaining = S * (S + 1) / 2;

		printf("%d\n", n * T + remaining == K);
		fflush(stdout);
	}

	return 0;
}
