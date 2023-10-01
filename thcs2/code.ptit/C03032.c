/*
Viết chương trình đếm xem trong đoạn [a,b] có bao nhiêu số là số nguyên tố và
tất cả các chữ số của nó cũng là số nguyên tố.

Input
Dòng đầu ghi số bộ test
Mỗi bộ test ghi 2 số a, b (1<a<b<10^6)

Output
Với mỗi bộ test, ghi ra số lượng số thỏa mãn trên một dòng.
Ví dụ:
Input:
2
10 100
1234 5678

Output:
4
26
*/

#include <stdio.h>
#include <string.h>

int prime_digit(long x) {
	while (x > 0) {
		char c = (x % 10) + '0';
		if (strchr("2357", c) == NULL) return 0;
		x /= 10;
	}
	return 1;
}

int main(void) {
	unsigned test;
	scanf("%u", &test);
	unsigned long a[test], b[test], max = 0, i, j;
	for (i = 0; i < test; i++) {
		scanf("%lu %lu", &a[i], &b[i]);
		if (b[i] > max) max = b[i];
	}
	char prime[max + 1];
	prime[0] = prime[1] = 0;
	for (i = 2; i <= max; i++) prime[i] = 1;
	for (i = 2; (unsigned long)i * i <= max; i++)
		if (prime[i])
			for (j = i * i; j <= max; j += i) prime[j] = 0;
	for (i = 0; i < test; i++) {
		unsigned long sum = 0;
		for (j = a[i]; j <= b[i]; j++)
			if (prime_digit(j)) sum += prime[j];
		printf("%ld\n", sum);
	}
	return 0;
}
