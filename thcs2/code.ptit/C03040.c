/*
Một số Smith là một số tự nhiên thỏa mãn tổng các chữ số của nó bằng với tổng
các chữ số của các thừa số nguyên tố của nó.

Nhiệm vụ của bạn là hãy xác định xem số nguyên N đã cho có là số Smith hay
không?

Ví dụ 1:
378 = 2 x 3 x 3 x 3 x 7
Tổng các chữ số là 3 + 7 + 8 = 18.
Tổng các chữ số của các nhân tử là 2 + 3 + 3 + 3 + 7 = 18.

Ví dụ 2:
4937775 = 3 x 5 x 5 x 65837.
Ta có 4 + 9 + 3 + 7 + 7 + 7 + 5 = 3 + 5 + 5 + 6 + 5 + 8 + 3 + 7 = 42.

Input
Chỉ có một số nguyên dương N không quá 9 chữ số.

Output
In ra “YES” nếu số đã cho là số Smith, in ra “NO” trong trường hợp ngược lại.

Ví dụ:
Input:          Output:
378             YES
120             NO
*/

#include <math.h>
#include <stdio.h>

int sum_of_digits(int n) {
	if (n == 0) return 0;
	return n % 10 + sum_of_digits(n / 10);
}

char is_smith(long n) {
	int sum = 0;
	long tmp = n, i;
	while (tmp > 0) {
		sum += tmp % 10;
		tmp /= 10;
	}
	for (i = 2; i <= sqrt(n); i++)
		if (n % i == 0) {
			unsigned exp = 0;
			while (n % i == 0) ++exp, n /= i;
			sum -= sum_of_digits(i) * exp;
		}
	if (n > 1) sum -= sum_of_digits(n);
	return sum == 0;
}

int main(void) {
	long n;
	scanf("%ld", &n);
	puts(is_smith(n) ? "YES" : "NO");
	return 0;
}
