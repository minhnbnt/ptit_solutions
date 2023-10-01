/*
Cho hai số nguyên dương n và k. Hãy kiểm tra xem giai thừa của n (n!) có chia
hết cho 2^k hay không.

Input
Có một dòng ghi 2 số n và k (1 ≤ n, k ≤ 100).

Output
Nếu n! chia hết cho 2^k thì in ra “Yes”, ngược lại in ra “No”.

Ví dụ:
Input:      Output:
5 3         Yes
1 1         No
*/

#include <stdio.h>

int main(void) {
	unsigned a, b;
	scanf("%u %u", &a, &b);
	while (a > 0) {
		unsigned tmp = a--;
		while (tmp % 2 == 0) {
			tmp /= 2;
			if (--b == 0) break;
		}
		if (b == 0) break;
	}
	puts(b ? "No" : "Yes");
	return 0;
}
