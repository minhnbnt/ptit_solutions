/*
Viết chương trình nhập vào một số n, không quá 10 chữ số.

Hãy thực hiện đếm số lần xuất hiện của các chữ số nguyên tố trong n và in ra màn
hình. (Liệt kê theo thứ tự xuất hiện các chữ số)

Input
Chỉ có một số nguyên dương N không quá 10 chữ số.

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

#include <math.h>
#include <stdio.h>

char prime(char x) {
	for (int i = 2; i <= sqrt(x); i++)
		if (x % i == 0) return 0;
	return x > 1;
}

int main() {
	long n;
	scanf("%ld", &n);
	char a[4][2], size = 0;
	while (n) {
		char x = n % 10;
		if (prime(x)) {
			char flag = 1;
			for (int j = 0; j < size; j++)
				if (a[j][0] == x) {
					a[j][1]++, flag = 0;
				};
			if (flag) {
				a[size][0] = x;
				a[size++][1] = 1;
			};
		};
		n /= 10;
	}
	for (int i = size - 1; i >= 0; i--) {
		printf("%d %d\n", a[i][0], a[i][1]);
	}
	return 0;
}
