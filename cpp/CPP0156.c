/*
Tìm số nghiệm của phương trình đồng dư x2 = 1(mod) p trong khoảng [1,b].  Ví dụ với b=5, p=7 ta tìm
được x = 1 €[1,5] để x2 = 1 %7=1. Với b = 8, p=6 ta tìm được x = {1, 5, 7} để x2 = 1(mod 7).

6%1 = 38%1 = 34%1 =0; 6%2 = 38%2 = 34%2 =0; 6%4 = 38%4 = 34%4 =2;

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi test là bộ đôi b, p. Các số được viết cách nhau một vài
khoảng trống.
T, b, p thỏa mãn ràng buộc : 1≤T≤100; 0≤b≤10^9; 1≤ p ≤10^5.

Output:
Đưa ra số các số kết quả mỗi test theo từng dòng.

Input:
2
5 7
8 6

Output:
1
3
*/

#include <stdio.h>

#define i64 long long

i64 count_solution(i64 range, i64 mod) {

	i64 i, counter = 0;
	for (i = 1; i < mod; ++i) {

		if ((i * i) % mod != 1) {
			continue;
		}

		i64 end = i + mod * (range / mod);

		if (end > range) {
			end -= mod;
		}

		counter += (end - i) / mod + 1;
	}

	return counter;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		i64 b, p;
		scanf("%lld%lld", &b, &p);

		printf("%lld\n", count_solution(b, p));
		fflush(stdout);
	}

	return 0;
}
