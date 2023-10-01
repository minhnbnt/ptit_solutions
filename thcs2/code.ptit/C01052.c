/*
Cho số nguyên dương N.

Nhiệm vụ của bạn là hãy xác định xem có bao nhiêu ước số của N chia hết cho 2?

Input:
Dòng đầu tiên là số lượng bộ test T (T ≤ 100).
Mỗi bộ test gồm một số nguyên N (1 ≤ N ≤ 10^9)

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

int main() {
	unsigned int n;
	scanf("%u", &n);
	unsigned result[n], i, j;
	for (i = 0; i < n; i++) {
		result[i] = 0;
		long long a;
		scanf("%lld", &a);
		int even = 0, odd = 1;
		while (a % 2 == 0) a /= 2, even++;
		for (j = 3; j <= sqrt(a); j += 2) {
			int conditions = 1;
			while (a % j == 0) {
				conditions++, a /= j;
			}
			odd *= conditions;
		};
		if (a > 1) odd *= 2;
		result[i] = even * odd;
	}
	for (int i = 0; i < n; i++) //
		printf("%u\n", result[i]);
	return 0;
}
