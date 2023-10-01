/*
Viết chương trình nhập vào số N không quá 4 chữ số, thực hiện liệt kê các số
thuận nghịch lớn hơn 1 và nhỏ hơn N thỏa mãn không chứa chữ số 9. Có bao nhiêu
số như vậy.

Input
Chỉ có một dòng ghi số n.

Output
Gồm hai dòng: dòng đầu liệt kê các số thỏa mãn, dòng thứ 2 ghi số lượng các số
tìm được.

Ví dụ:

Input:
100

Output:
2 3 4 5 6 7 8 11 22 33 44 55 66 77 88
15
*/

#include <stdio.h>

char beautyof(int n) {
	int tmp = n, a = 0;
	while (tmp > 0) {
		char c = tmp % 10;
		if (c == 9) return 0;
		a = a * 10 + c;
		tmp /= 10;
	}
	return a == n;
}

int main(void) {
	unsigned n, i, count = 0;
	scanf("%u", &n);
	for (i = 2; i < n; i++)
		if (beautyof(i)) {
			printf("%u ", i);
			++count;
		}
	printf("\n%u\n", count);
	return 0;
}
