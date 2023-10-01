/*
Viết chương trình C cho phép nhập vào hai số a và b (a có thể lớn hơn b). Liệt
kê các sô Strong nằm trong đoạn a,b.

Các kết quả thỏa mãn liệt kê cách nhau một khoảng trống.

Input:
Chỉ có một dòng ghi hai số a,b.

Output:
Ghi ra kết quả tính toán trên một dòng

Ví dụ:
Input:
1 1000

Output:
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
	return !n;
}

int main(void) {
	long a, b, i;
	scanf("%ld %ld", &a, &b);
	if (a > b) {
		long tmp = a;
		a = b;
		b = tmp;
	}
	for (i = a; i <= b; i++)
		if (strong_number(i)) printf("%ld ", i);
	putchar('\n');
	return 0;
}
