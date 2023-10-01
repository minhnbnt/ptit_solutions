/*
Viết chương trình nhập vào 2 số nguyên dương a và b không quá 6 chữ số. Hãy so
sánh và xếp lại theo thứ tự tăng dần tổng các chữ số. (Nếu a và b có tổng các
chữ số bằng nhau thì in ra a trước)

Ví dụ:
Input:
99 1111

Output:
1111 99
*/

#include <stdio.h>

int sum_of_digit(long a) {
	if (a == 0) return 0;
	return a % 10 + sum_of_digit(a / 10);
}

int main(void) {
	long a, b;
	scanf("%ld %ld", &a, &b);
	if (sum_of_digit(a) > sum_of_digit(b)) {
		long tmp = a;
		a = b;
		b = tmp;
	}
	printf("%ld %ld\n", a, b);
	return 0;
}
