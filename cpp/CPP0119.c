/*
Cho số nguyên dương N.

Nhiệm vụ của bạn là hãy xác định xem có bao nhiêu ước số của N chia hết cho 2?

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi bộ test gồm một số nguyên N (1 ≤ N ≤ 109)

Output:
Với mỗi test, in ra đáp án tìm được trên một dòng.

Ví dụ:
Input:
2
9
8

Output:
0
3
*/

#include <math.h>
#include <stdio.h>

#define u64 unsigned long long

int main(void) {

	unsigned cases;
	scanf("%u", &cases);

	while (cases--) {

		u64 x, i, result = 0;
		scanf("%llu", &x);

		while (x % 2 == 0) {
			x /= 2;
			++result;
		}

		for (i = 3; i <= sqrt(x); ++i) {
			unsigned count = 1;
			while (x % i == 0) {
				x /= i;
				++count;
			}
			result *= count;
		}
		if (x > 1) result *= 2;

		printf("%llu\n", result);
		fflush(stdout);
	}

	return 0;
}
