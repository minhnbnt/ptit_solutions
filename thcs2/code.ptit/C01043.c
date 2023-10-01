/*
Số Strong là số thỏa mãn có tổng giai thừa các chữ số của nó bằng chính nó. Ví
dụ: 145 = 1! + 4! + 5!

Viết chương trình nhập vào số n không quá 6 chữ số và kiểm tra xem n có phải số
Strong hay không. Nếu đúng in ra 1 sai in ra 0.

Input
Chỉ có một dòng ghi số N (không quá 6 chữ số)

Output
Ghi ra 1 hoặc 0

Ví dụ
Input:
145
Output:
1
*/

#include <stdio.h>

char strong(long n) {
	long temp = n, sum = 0;
	while (temp) {
		char a = temp % 10;
		long add = 1;
		while (a > 0) add *= a--;
		sum += add;
		temp /= 10;
	}
	return n == sum;
}

int main() {
	long n;
	scanf("%ld", &n);
	printf("%d\n", strong(n));
	return 0;
}
