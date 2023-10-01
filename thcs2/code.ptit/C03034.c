/*
Cho số nguyên dương N.

Nhiệm vụ của bạn là hãy xác định xem có bao nhiêu ước của N chia hết cho 2?

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
	int n;
	scanf("%d", &n);
	while (n--) {
		unsigned long a;
		scanf("%lu", &a);
		int div = 2, even = 0;
		int variant = 1;
		while (a % 2 == 0) a /= 2, even++;
		for (int i = 3; i <= sqrt(a); i += 2) {
			int odd = 1;
			while (a % i == 0) a /= i, odd++;
			variant *= odd;
		}
		if (a > 1) variant *= 2;
		printf("%d\n", variant * even);
	}
	return 0;
}
