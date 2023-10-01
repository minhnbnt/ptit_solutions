/*
Số Strong là số thỏa mãn có tổng giai thừa các chữ số của nó bằng chính nó. Ví
dụ: 145 = 1! + 4! + 5!

Viết chương trình nhập vào số n không quá 9 chữ số và liệt kê các số Strong nhỏ
hơn n (Các kết quả thỏa mãn được liệt kê trên một dòng cách nhau một khoảng
trống)

Input:
Chỉ có một dòng ghi số n.

Output:
Ghi ra kết quả tính toán trên một dòng

Ví dụ:
Input
1000

Output
1 2 145
*/

#include <stdio.h>

int factoral(int x) {
	if (x == 0) return 1;
	return x * factoral(x - 1);
}

char strong_number(long n) {
	long tmp = n;
	while (tmp > 0) {
		n -= factoral(tmp % 10);
		tmp /= 10;
	}
	return n == 0;
}

int main(void) {
	long n, i;
	scanf("%ld", &n);
	for (i = 1; i <= n; i++)
		if (strong_number(i)) {
			printf("%ld ", i);
		}
	putchar('\n');
	return 0;
}
