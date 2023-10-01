/*
Cho hai số nguyên không âm N và K.
Nhiệm vụ của bạn là tìm S = 1%K + 2%K + ..+ N%K.

Ví dụ với N = 10, K=2 ta có:
S = 1%2 + 2%2+3%2 + 4%2+5%2+6%2+7%2+8%2+9%2+10%2 = 5.
Yêu cầu độ phức tạp thuật toán là hằng số

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
55
1
*/

#include <stdio.h>

#define u64 unsigned long long

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 N, K;
		scanf("%llu%llu", &N, &K);

		u64 n = N / K;
		u64 T = K * (K + 1) / 2 - K;
		u64 remaining = N % K;
		u64 sum_remaining = remaining * (remaining + 1) / 2;

		printf("%llu\n", n * T + sum_remaining);
		fflush(stdout);
	}

	return 0;
}
