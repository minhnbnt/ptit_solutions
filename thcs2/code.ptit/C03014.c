/*
Tìm bội số chung nhỏ nhất và ước số chung lớn nhất của hai số nguyên dương a, b.

Input:
Dòng đầu tiên đưa vào T là số lượng bộ test.
T dòng tiếp theo mỗi dòng có một cặp số a, b.
T, a, b thỏa mãn ràng buộc: 1≤T≤100; 1≤a, b≤108;

Output:
Đưa ra kết quả mỗi test theo từng dòng.
Ví dụ:
Input:
2
5 10
14 8

Output:
10 5
56 2
*/

#include <stdio.h>

int main(void) {
	unsigned test;
	scanf("%u", &test);
	while (test--) {
		unsigned long a, b;
		scanf("%lu %lu", &a, &b);
		unsigned long long mul = a * b;
		while (a != b)
			if (a > b) a -= b;
			else b -= a;
		printf("%lld %ld\n", mul / a, b);
	}
	return 0;
}
