/*
Viết chương trình nhập vào một số n, không quá 18 chữ số.
Hãy thực hiện đếm số lần xuất hiện của các chữ số nguyên tố trong n và in ra màn
hình. (Liệt kê theo thứ tự xuất hiện các chữ số)

Input
Chỉ có một số nguyên dương N không quá 18 chữ số.

Output
Ghi ra kết quả, mỗi dòng ghi một số nguyên tố và số lần xuất hiện theo thứ tự
xuất hiện.

Ví dụ

Input:
112345

Output:
2 1
3 1
5 1
*/

#include <stdio.h>

const char prime_digit[] = { 2, 3, 5, 7 };
unsigned digit[10] = { 0 };

int main(int argc, char *argv[]) {
	unsigned long long n;
	scanf("%llu", &n);
	while (n > 0) {
		digit[n % 10]++;
		n /= 10;
	}
	for (int i = 0; i < 4; i++)
		if (digit[prime_digit[i]] > 0)
			printf("%d %u\n", //
			       prime_digit[i], digit[prime_digit[i]]);
	return 0;
}
