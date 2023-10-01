/*
Viết chương trình liệt kê các số nguyên tố nhỏ hơn N với N là một số nguyên
dương không quá 106.

Input
Dữ liệu vào chỉ có duy nhất một số N.

Output
Kết quả ghi mỗi số nguyên tố trên một dòng, theo thứ tự từ nhỏ đến lớn.

Ví dụ:
Input:
10

Output:
2
3
5
7
*/

// recursive function only :D

#include <stdio.h>

void init(char *prime, long range) {
	if (range < 2) {
		prime[0] = prime[1] = 0;
		return;
	}
	prime[range] = 1;
	init(prime, range - 1);
}

void sieve(char *prime, int gap, long pos, long range) {
	if (pos > range) return;
	prime[pos] = 0;
	sieve(prime, gap, pos + gap, range);
}

void calculate(char *prime, int i, long range) {
	if ((long)i * i > range) return;
	if (prime[i]) sieve(prime, i, i * i, range);
	calculate(prime, i + 1, range);
}

void print(char *prime, long pos, long range) {
	if (range < pos) return;
	if (prime[pos]) printf("%ld\n", pos);
	print(prime, pos + 1, range);
}

int main(void) {
	long n;
	scanf("%ld", &n);
	char prime[n];
	init(prime, n);
	calculate(prime, 2, n - 1);
	print(prime, 0, n - 1);
	return 0;
}
