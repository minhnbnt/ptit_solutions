/*
Cho số nguyên dương n. Hãy kiểm tra xem n có phải là số trong dãy Fibonacci hay
không?

Input:
Dòng đầu tiên đưa vào số lượng bộ test T.
Những dòng kế tiếp đưa vào các bộ test. Mỗi bộ test là một số nguyên dương n.
T, n thỏa mãn ràng buộc :0 ≤ T ≤ 100; 1≤n≤10^18.

Output:
Đưa ra “YES” hoặc “NO” tương ứng với n là số Fibonacci hoặc không phải số
Fibonacci của mỗi test theo từng dòng.

Ví dụ:
Input:
2
8
15

Output:
YES
NO
*/

#include <stdio.h>

int main() {
	unsigned n, i;
	scanf("%u", &n);
	while (n--) {
		unsigned long long a, f1 = 0, f2 = 1;
		scanf("%llu", &a);
		while (a > f1) {
			unsigned long long tmp = f2;
			f2 += f1, f1 = tmp;
		}
		puts(a == f1 ? "YES" : "NO");
	}
	return 0;
}
