/*
Cho ba số nguyên dương x, y, p. Nhiệm vụ của bạn là tính (xy) %p. Ví dụ với x =
2, y = 3, p = 5 thì (23)%5=3.

Input:
Dòng đầu tiên đưa vào số lượng test T.
Những dòng kế tiếp mỗi dòng đưa vào một test. Mỗi test là bộ ba x, y, p được
viết cách nhau một vài khoảng trống.

T, x, y, p thỏa mãn ràng buộc : 1≤T≤100; 1≤x, y≤10^6; 1≤P≤10^9+7.

Output:
Đưa ra kết quả mỗi test theo từng dòng.

Input:
2
2 3 5
3 2 4

Output:
3
1
*/

#include <stdio.h>

#define u64 unsigned long long

u64 bin_pow(u64 x, u64 y, const u64 p) {

	u64 result = 1;

	while (y > 0) {

		if (y & 1) result = (result * x) % p;

		x = (x * x) % p, y /= 2;
	}

	return result;
}

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 x, y, p;
		scanf("%llu%llu%llu", &x, &y, &p);

		printf("%llu\n", bin_pow(x, y, p));
		fflush(stdout);
	}

	return 0;
}
