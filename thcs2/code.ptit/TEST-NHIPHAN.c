/* Nhập vào số nguyên dương a có không quá 3 chữ số. Hãy in biểu diễn dưới dạng
nhị phân của số a. */

#include <stdio.h>

int main() {
	char arr[10] = { 0 }, i = 10;
	unsigned n;
	scanf("%u", &n);
	if (n) {
		while (n > 0) {
			arr[--i] = n % 2;
			n /= 2;
		}
		while (i < 10) {
			printf("%d", arr[i++]);
		}
	} else putchar('0');
	putchar('\n');
	return 0;
}
