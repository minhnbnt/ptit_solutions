/*
Cho số tự nhiên N và số nguyên tố P. Nhiệm vụ của bạn là tìm số x lớn nhất để N!
chia hết cho px. Ví dụ với N=7, p=3 thì x=2 là số lớn nhất để 7! Chia hết
cho 32.

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là cặp số N, p được viết
cách nhau một vài khoảng trống.
T, N, p thỏa mãn rang buộc : 1≤T≤100; 1≤N≤10^5; 2≤p≤5000;

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
3
62 7
76 2
3 5

Output:
9
73
0
*/

#include <stdio.h>

#define u64 unsigned long long

unsigned calculate(u64 N, unsigned p) {

	unsigned result = 0;

	for (u64 i = 2; i <= N; ++i) {

		u64 cloned = i;

		while (cloned % p == 0) {
			++result;
			cloned /= p;
		}
	}

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 N;
		unsigned p;
		scanf("%llu%u", &N, &p);

		printf("%u\n", calculate(N, p));
		fflush(stdout);
	}

	return 0;
}
