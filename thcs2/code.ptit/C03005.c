/*
Viết chương trình nhập hai số nguyên dương a,b thỏa mãn 2<a<b<100.

Một cặp số (i,j) được gọi là nguyên tố cùng nhau nếu i ≠ j và ước số chung lớn
nhất của i với j là 1. Hãy liệt kê các cặp số nguyên tố cùng nhau trong đoạn
[a,b] theo thứ tự từ nhỏ đến lớn.

Input
Chỉ có một dòng ghi hai số a,b

Output
Các cặp số i,j thỏa mãn được viết lần lượt trên từng dòng theo định dạng (i,j),
theo thứ tự từ điển.

Ví dụ:
Input:
5 8

Output:
(5,6)
(5,7)
(5,8)
(6,7)
(7,8)
*/

#include <stdio.h>

int gcd(int a, int b) {
	if (!a) return b;
	return gcd(b % a, a);
}

int main(void) {
	int a, b, i, j;
	scanf("%d %d", &a, &b);
	for (i = a; i < b; i++)
		for (j = i + 1; j <= b; j++)
			if (gcd(i, j) == 1) {
				printf("(%d,%d)\n", i, j);
			}
	return 0;
}
