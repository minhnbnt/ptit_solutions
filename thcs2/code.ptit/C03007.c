/*
Viết chương trình liệt kê các số vừa nguyên tố, vừa thuận nghịch trong đoạn
[a,b] với a,b là các số nguyên dương thỏa mãn 10<a<b<106.

Input
Dòng đầu ghi số bộ test. Mỗi bộ test là một cặp số a,b.

Output
Với mỗi bộ test, ghi lần lượt các số thỏa mãn, mỗi số cách nhau một khoảng
trống, mỗi dòng ghi đúng 10 số. Khi hết một test thì bỏ trống một dòng trước khi
ghi kết quả test tiếp theo.

Ví dụ:
Input:
2
20 1234
123 140

Output:
101 131 151 181 191 313 353 373 383 727
757 787 797 919 929
131
*/

#include <stdio.h>

char revertable(unsigned long n) {
	unsigned long m = n, r = 0;
	while (m > 0) {
		r = r * 10 + m % 10;
		m /= 10;
	}
	return r == n;
}

int main(void) {
	unsigned test, i, j;
	scanf("%u", &test);
	unsigned long a[test], b[test], max = 0;
	for (i = 0; i < test; i++) {
		scanf("%lu %lu", &a[i], &b[i]);
		if (b[i] > max) max = b[i];
	}
	char prime[max + 1];
	prime[0] = prime[1] = 0;
	for (long i = 2; i <= max; i++) prime[i] = 1;
	for (i = 2; (long)i * i <= max; i++)
		if (prime[i])
			for (j = i * i; j <= max; j += i) {
				prime[j] = 0;
			}
	for (i = 0; i < test; i++) {
		int count = 0;
		while (a[i] <= b[i]) {
			if (prime[a[i]] && revertable(a[i])) {
				printf("%lu", a[i]);
				if (++count == 10) {
					putchar('\n');
					count = 0;
				} else putchar(' ');
			}
			++a[i];
		}
		if (count) putchar('\n');
	}
	return 0;
}
