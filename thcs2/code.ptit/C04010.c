/*
Viết chương trình nhập vào mảng A gồm n phần tử số nguyên (2 < n < 100). Tìm giá
trị nhỏ nhất và nhỏ thứ hai và in ra.
Dữ liệu vào đảm bảo luôn có ít nhất 2 số khác nhau.

Input
Dòng thứ nhất là số phần tử của mảng A.
Dòng thứ hai là các phần tử của mảng A

Output
Giá trị nhỏ nhất và giá trị nhỏ thứ hai

Ví dụ:
Input:
6
80 23 79 58 11 10

Output:
10 11
*/

#include <stdio.h>

int main() {
	int n, i;
	scanf("%d", &n);
	int x, min1 = __INT32_MAX__, min2 = __INT32_MAX__;
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x < min1) min2 = min1, min1 = x;
		else if (x == min1) continue;
		else if (x < min2) min2 = x;
	}
	printf("%d %d\n", min1, min2);
	return 0;
}
