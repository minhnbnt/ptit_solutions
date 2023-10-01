/*
Một số được coi là đẹp nếu nó là số nguyên tố và tổng chữ số là một số trong dãy
Fibonaci. Viết chương trình liệt kê trong một đoạn giữa hai số nguyên cho trước
có bao nhiêu số đẹp như vậy

Input
Chỉ có một dòng ghi hai số nguyên dương a,b (a có thể lớn hơn b) không quá 1000.

Output
Ghi ra các số thỏa mãn trên một dòng, cách nhau một khoảng trống.

Ví dụ:
Input:
2 50

Output:
2 3 5 11 17 23 41
*/

#include <stdio.h>

char in_fibonacci(unsigned n) {
	unsigned a = 0, b = 1, tmp;
	while (n > a) {
		tmp = a;
		a = b;
		b += tmp;
	}
	return n == a;
}

int main(void) {
	unsigned a, b, i, j;
	scanf("%u %u", &a, &b);
	if (a > b) {
		unsigned tmp = a;
		a = b;
		b = tmp;
	}
	char prime[b + 1];
	prime[0] = prime[1] = 0;
	for (i = 2; i <= b; i++) prime[i] = 1;
	unsigned x = 0, y = 1;
	for (i = 2; (long)i * i <= b; i++)
		if (prime[i])
			for (j = i * i; j <= b; j += i) prime[j] = 0;
	for (i = a; i <= b; i++)
		if (prime[i]) {
			unsigned sum = 0, tmp = i;
			while (tmp > 0) {
				sum += tmp % 10;
				tmp /= 10;
			}
			if (in_fibonacci(sum)) printf("%u ", i);
		}
	putchar('\n');
	return 0;
}
