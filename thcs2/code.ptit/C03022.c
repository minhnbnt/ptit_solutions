/*
Viết chương trình nhập vào số nguyên dương n không quá 5 chữ số. Thực hiện liệt
kê các số nguyên tố nhỏ hơn n và thỏa mãn có tổng các chữ số chia hết cho 5. Có
bao nhiêu số như vậy.

Input
Chỉ có một dòng ghi số n.

Output
Gồm hai dòng: dòng đầu liệt kê các số thỏa mãn, dòng thứ 2 ghi số lượng các số
tìm được.

Ví dụ:
Input:
100

Output:
5 19 23 37 41 73
6
*/

#include <math.h>
#include <stdio.h>

int sumOfDigits(unsigned long n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main(void) {
	unsigned long n, i, j;
	scanf("%lu", &n);
	char prime[n + 1];
	prime[0] = prime[1] = 0;
	for (i = 2; i <= n; i++) prime[i] = 1;
	for (i = 2; i <= sqrt(n); i++)
		if (prime[i])
			for (j = i * i; j <= n; j += i) prime[j] = 0;
	unsigned count = 0;
	for (i = 0; i <= n; i++)
		if (prime[i] && sumOfDigits(i) % 5 == 0) {
			printf("%lu ", i);
			++count;
		}
	printf("\n%u\n", count);
	return 0;
}
