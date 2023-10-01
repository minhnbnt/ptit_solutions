/*
Cho hai số tự nhiên n, m . Nhiệm vụ của bạn là tìm số nguyên nhỏ nhất chia hết
cho n , n+1, .., m.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
T dòng tiếp theo mỗi dòng đưa vào một bộ test. Mỗi bộ test là 2 số tự nhiên n,
m. T thỏa mãn ràng buộc: 1≤T≤10^4; 1≤n, m≤40

Output:
Đưa ra kết quả mỗi test theo từng dòng.


Input:
2
1 3
3 5

Output:
6
60
*/

#include <stdio.h>

#define ll long long
#define lll __int128_t

ll lcm(ll a, int b) {
	lll c = a * b;
	while (a && b)
		if (a > b) a %= b;
		else b %= a;
	return c / (a + b);
}

int main(void) {
	unsigned int n;
	scanf("%u", &n);
	int a, b;
	while (n--) {
		scanf("%d %d", &a, &b);
		ll c = 1;
		while (b >= a) {
			if (c % b) c = lcm(c, b);
			--b;
		}
		printf("%lld\n", c);
	}
	return 0;
}
