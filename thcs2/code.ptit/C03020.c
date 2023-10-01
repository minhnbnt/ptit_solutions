/*
Một số được coi là số đẹp nếu nó là số thuận nghịch, có chứa ít nhất một chữ số
6, và tổng các chữ số của nó có chữ số cuối cùng là 8.

Viết chương trình liệt kê trong một đoạn giữa hai số nguyên [a,b] cho trước có
bao nhiêu số đẹp như vậy

Input:
Chỉ có một dòng ghi hai số a,b.

Output:
Ghi ra kết quả tính toán trên một dòng

Ví dụ:
Input:
1 500

Output:
161
*/

#include <stdio.h>

char check6(long long n) {
	if (n < 0) n = -n;
	while (n != 0) {
		if (n % 10 == 6) return 1;
		n /= 10;
	}
	return 0;
}

int sumOfDigits(long long n) {
	if (n < 0) n = -n;
	int sum = 0;
	while (n != 0) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

char revertable(long long n) {
	if (n < 0) n = -n;
	long long rev = 0, tmp = n;
	while (tmp != 0) {
		rev = rev * 10 + tmp % 10;
		tmp /= 10;
	}
	return rev == n;
}

int main(void) {
	long long a, b;
	scanf("%lld %lld", &a, &b);
	if (a > b) {
		long long tmp = a;
		a = b;
		b = tmp;
	}
	do
		if (revertable(a) && check6(a) //
		    && sumOfDigits(a) % 10 == 8)
			printf("%lld ", a);
	while (++a <= b);
	putchar('\n');
	return 0;
}
